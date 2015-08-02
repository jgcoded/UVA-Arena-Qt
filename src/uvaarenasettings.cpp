#include "uvaarenasettings.h"

using namespace uva;

const QString KeyUserName = "UserName";
const QString DefaultUserName = "";

const QString KeyUserId = "UserId";
const qint32 DefaultUserId = -1;

const QString KeyMaxDaysUntilProblemListRedownload =
    "MaxDaysUntilProblemListRedownload";
const qint64 DefaultMaxDaysUntilProblemListRedownload = 1;

const QString KeyMaxProblemsTableRowsToFetch = "MaxProblemsListRowsToLoad";
const qint32 DefaultMaxProblemsTableRowsToFetch = 50;

typedef UVAArenaSettings::ProblemFormat ProblemFormat;
const QString KeyProblemFormatPreference = "ProblemFormatPreference";
const ProblemFormat DefaultProblemFormatPreference = ProblemFormat::PDF;

const QString KeyLiveEventsUpdateInterval = "JudgeStatusUpdateInterval";
const qint32 DefaultLiveEventsUpdateInterval = 10000;

QString KeyLiveEventsAutoStart = "LiveEventsAutoStart";
bool DefaultLiveEventsAutoStart = false;

const QString KeySavePDFDocumentsOnDownload = "SavePDFDocumentsOnDownload";
const bool DefaultSavePDFDocumentsOnDownload = true;

QString KeyMaxDaysUntilCategoryIndexRedownload =
    "MaxDaysUntilCategoryIndexRedownload";
qint64 DefaultMaxDaysUntilCategoryIndexRedownload = 31;


QString UVAArenaSettings::userName()
{
    return settings.value(KeyUserName, DefaultUserName).toString();
}

void UVAArenaSettings::setUserName(QString userName)
{
    settings.setValue(KeyUserName, userName);
}

qint32 UVAArenaSettings::userId()
{
    return settings.value(KeyUserId, DefaultUserId).toInt();
}

void UVAArenaSettings::setUserId(qint32 userId)
{
    settings.setValue(KeyUserId, userId);
}

qint64 UVAArenaSettings::maxDaysUntilProblemListRedownload()
{
    return settings.value(KeyMaxDaysUntilProblemListRedownload,
        DefaultMaxDaysUntilProblemListRedownload).toLongLong();
}

void UVAArenaSettings::setMaxDaysUntilProblemListRedownload(qint64 days)
{
    settings.setValue(KeyMaxDaysUntilProblemListRedownload, days);
}

qint32 UVAArenaSettings::maxProblemsTableRowsToFetch()
{
    return settings.value(KeyMaxProblemsTableRowsToFetch,
        DefaultMaxProblemsTableRowsToFetch).toInt();
}

void UVAArenaSettings::setMaxProblemsTableRowsToFetch(qint32 numRows)
{
    settings.setValue(KeyMaxProblemsTableRowsToFetch, numRows);
}

ProblemFormat UVAArenaSettings::problemFormatPreference()
{
    return (ProblemFormat)settings.value(KeyProblemFormatPreference,
        (int)DefaultProblemFormatPreference).toInt();
}

void UVAArenaSettings::setProblemFormatPreference(ProblemFormat format)
{
    settings.setValue(KeyProblemFormatPreference, (int)format);
}

int UVAArenaSettings::liveEventsUpdateInterval()
{
    return settings.value(KeyLiveEventsUpdateInterval,
        DefaultLiveEventsUpdateInterval).toInt();
}

void UVAArenaSettings::setLiveEventsUpdateInterval(int msecs)
{
    settings.setValue(KeyLiveEventsUpdateInterval, msecs);
}

bool uva::UVAArenaSettings::liveEventsAutoStart()
{
    return settings.value(KeyLiveEventsAutoStart
        , DefaultLiveEventsAutoStart).toBool();
}

void uva::UVAArenaSettings::setLiveEventsAutoStart(bool autostart)
{
    settings.setValue(KeyLiveEventsAutoStart, autostart);
}

bool UVAArenaSettings::savePDFDocumentsOnDownload()
{
    return settings.value(KeySavePDFDocumentsOnDownload,
        DefaultSavePDFDocumentsOnDownload).toBool();
}

void UVAArenaSettings::setSavePDFDocumentsOnDownload(bool autosave)
{
    settings.setValue(KeySavePDFDocumentsOnDownload, autosave);
}

qint64 UVAArenaSettings::maxDaysUntilCategoryIndexRedownload()
{
    return settings.value(KeyMaxDaysUntilCategoryIndexRedownload,
        DefaultMaxDaysUntilCategoryIndexRedownload).toLongLong();
}

void UVAArenaSettings::setMaxDaysUntilCategoryIndexRedownload(qint64 days)
{
    settings.setValue(KeyMaxDaysUntilCategoryIndexRedownload, days);
}
