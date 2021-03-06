#pragma once

#include "uvalib_global.h"

#include <QWidget>
#include <mupdf-qt.h>

#include <memory>
#include <vector>

namespace uva
{

    class UVA_EXPORT MuPDFWidget : public QWidget
    {
        Q_OBJECT

    public:
        MuPDFWidget(QWidget *parent = 0);

        int numPages();

    public slots:

        /*!
            \brief Load a document from a copy of a PDF File raw data.

            This is a copy because mupdf does not make its own copy
            of the PDF data.
        */
        void loadDocument(QByteArray data);

        void loadDocument(const QString &filePath);

        void setPage(int pageNum);

        void clear();

        void zoomIn();

        void zoomOut();

        void setZoom(double amount);

        void setRenderAllPages(bool renderAll);

    protected:

        virtual void paintEvent(QPaintEvent *event) override;

    private:

        void setupPages();
        void resizeToDocument();

        qreal mWidth;
        qreal mHeight;
        qreal mMaxWidth;
        qreal mTotalHeight;
        qreal mScale;
        int mCurrentPageIndex;
        bool mRenderAllPages;

        QByteArray mData;
        std::unique_ptr<MuPDF::Document> mPDFDocument;
        std::vector<std::unique_ptr<MuPDF::Page> > mPages;

    };
}
