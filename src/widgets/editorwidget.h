#pragma once

#include "uvalib_global.h"
#include "uvaarenawidget.h"
#include <QWidget>

namespace uva
{

    namespace Ui {
        class EditorWidget;
    }

    class UVA_EXPORT EditorWidget : public UVAArenaWidget
    {
        Q_OBJECT

    public:
        explicit EditorWidget(QWidget *parent = 0);
        ~EditorWidget();

        virtual void initialize() override;

    public slots:

        virtual void onUVAArenaEvent(UVAArenaEvent, QVariant = 0) override;

    private:
        std::unique_ptr<Ui::EditorWidget> mUi;
    };

}