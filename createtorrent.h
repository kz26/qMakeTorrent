#ifndef CREATETORRENT_H
#define CREATETORRENT_H

#include <QThread>

class CreateTorrent : public QThread
{
    Q_OBJECT
public:
    explicit CreateTorrent(QObject *parent = 0);
    void makeTorrentFiles(QString source, bool isBatch, QString announceUrls, QString webSeeds, QString comment, QString creator, int pieceSizeIndex, bool isPrivate);
    void sendProgressSignal(int i);
signals:
    void updateProgress(int i);
    void logStatusMessage(QString msg);

public slots:
    
private:
    void run();
    QString source;
    bool isBatch;
    QString announceUrls;
    QString webSeeds;
    QString comment;
    QString creator;
    int pieceSize;
    bool isPrivate;
    int pieceCount;

};

#endif // CREATETORRENT_H
