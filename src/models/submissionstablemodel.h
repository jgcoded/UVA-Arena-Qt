#pragma once
#include "arenatablemodel.h"

namespace uva
{
    class SubmissionsTableModel : public ArenaTableModel
    {

    public:

        SubmissionsTableModel();

        void setSubmissionsList(QList<UserSubmission> submissions);

        virtual QVariant dataAtIndex(const QModelIndex &index) const override;

        virtual int dataCount() const override;

        virtual QVariant style(const QModelIndex &index, int role) const override;

        void setProblemMap(std::shared_ptr<Uhunt::ProblemMap> problemMap);

    private:
        QList<UserSubmission> mSubmissions;
        std::shared_ptr<Uhunt::ProblemMap> mProblemMap;
    };
}