#pragma once

#include "arenatablemodel.h"
#include "mainwindow.h"
#include "Uhunt/uhunt.h"
#include <QList>
#include <memory>

namespace uva
{

    class UVA_EXPORT LiveEventsTableModel : public ArenaTableModel
    {
    public:
        LiveEventsTableModel();

        void setStatusData(Uhunt::LiveEventMap statusData);

        void setProblemMap(std::shared_ptr<Uhunt::ProblemMap> problemMap);

        qint64 getLastSubmissionId();

        virtual QVariant getModelDataAtIndex(const QModelIndex &index) const override;

    protected:

        virtual int getDataCount() const;

        virtual QVariant getDataAtIndex(const QModelIndex &index) const;

    private:

        QList<qint64> mRowToId;
        Uhunt::LiveEventMap mStatusData;
        std::shared_ptr<Uhunt::ProblemMap> mProblemMap;
    };
}