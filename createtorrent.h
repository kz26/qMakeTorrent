#ifndef CREATETORRENT_H
#define CREATETORRENT_H

#include <QThread>

class CreateTorrent : public QThread
{
    Q_OBJECT
public:
    explicit CreateTorrent(QObject *parent = 0);
    void makeTorrentFiles(QString source, bool isBatch, QString comment, QString creator, int pieceSize, bool isPrivate);
signals:
    void updateProgress(int i);

public slots:
    
private:
    void run();
    QString source;
    bool isBatch;
    QString comment;
    QString creator;
    int pieceSize;
    bool isPrivate;
    int pieceCount;
    void sendProgressSignal(int i, int total);

};

#endif // CREATETORRENT_H
