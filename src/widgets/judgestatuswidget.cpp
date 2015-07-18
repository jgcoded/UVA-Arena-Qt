#include "judgestatuswidget.h"
#include "ui_judgestatuswidget.h"
#include "mainwindow.h"
#include "commons/colorizer.h"

using namespace uva;

class StatusModelStyle : public ModelStyle
{
public:
    StatusModelStyle(ArenaTableModel *owner = nullptr)
        : ModelStyle(owner)
    {
    }

    virtual QVariant Style(const QModelIndex &index, int role) override
    {
        switch (role)
        {
        case Qt::ForegroundRole:
            switch (index.column())
            {
            case 0: //submission id
                return QBrush(Colorizer::tan);
            case 1: //username
                return QBrush(Colorizer::goldenRod);
            case 2: //full name
                return QBrush(Colorizer::lightCoral);
            case 3: //number
                return QBrush(Colorizer::antiqueWhite);
            case 4: //title
                return QBrush(Colorizer::cyan);
            case 5: //language
                return QBrush(Colorizer::burlyWood);
            case 6: //verdict
                if (mOwner)
                    return QBrush(Colorizer::getVerdictColor((Verdict)mOwner->getModelDataAtIndex(index).toInt()));
            case 7: //runtime
                return QBrush(Colorizer::cornsilk);
            case 8: //rank                
                return QBrush(Colorizer::gold);
            case 9: //submission time                
                return QBrush(Colorizer::snow);
            default:
                return QBrush(Colorizer::white);
            }

        default:
            return ModelStyle::Style(index, role);
        }
    }
};

JudgeStatusWidget::JudgeStatusWidget(QWidget *parent) :
    UVAArenaWidget(parent),
    ui(new Ui::JudgeStatusWidget)
{
    ui->setupUi(this);
    mStatusTableModel.setModelStyle(std::make_unique<StatusModelStyle>(&mStatusTableModel));
    ui->statusTableView->setModel(&mStatusTableModel);

    mTimer = new QTimer(this);
    QObject::connect(mTimer, &QTimer::timeout, this, &JudgeStatusWidget::refreshJudgeStatus);
}

JudgeStatusWidget::~JudgeStatusWidget()
{
    delete ui;
}

void JudgeStatusWidget::initialize()
{
    //connect judge status downloaded signal
    QObject::connect(mUhuntApi.get(), &Uhunt::judgeStatusDownloaded, this, &JudgeStatusWidget::setStatusData);

    mTimer->start(mSettings.getJudgeStatusUpdateInterval());
}

void JudgeStatusWidget::refreshJudgeStatus()
{
    mUhuntApi->getJudgeStatus(mStatusTableModel.getLastSubmissionId());
}

void JudgeStatusWidget::setProblemMap(std::shared_ptr<Uhunt::ProblemMap> problemMap)
{
    mProblemMap = problemMap;
}

void JudgeStatusWidget::setStatusData(Uhunt::JudgeStatusMap statusData)
{
    mStatusTableModel.setStatusData(statusData, mProblemMap);
    emit newUVAArenaEvent(UVAArenaEvent::UPDATE_STATUS, "Judge Status updated.");
}

void JudgeStatusWidget::onUVAArenaEvent(UVAArenaEvent arenaEvent, QVariant metaData)
{
    switch (arenaEvent)
    {
    case UVAArenaEvent::UPDATE_STATUS:
        break;

    default:
        break;
    }
}
