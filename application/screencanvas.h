#ifndef SCREENCANVAS_H
#define SCREENCANVAS_H

#include <QColor>
#include <QImage>
#include <QByteArray>
#include <QQuickPaintedItem>

class ScreenCanvas : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(qreal canvasWidth READ canvasWidth WRITE setCanvasWidth NOTIFY canvasWidthChanged)
    Q_PROPERTY(qreal canvasHeight READ canvasHeight WRITE setCanvasHeight NOTIFY canvasHeightChanged)
    Q_PROPERTY(qreal renderWidth READ renderWidth NOTIFY renderWidthChanged)
    Q_PROPERTY(qreal renderHeight READ renderHeight NOTIFY renderHeightChanged)
    Q_PROPERTY(QByteArray data READ data WRITE setData)

public:
    ScreenCanvas(QQuickItem *parent = nullptr);

    const QByteArray &data() const;
    void setData(const QByteArray &data);

    void paint(QPainter *painter) override;

    qreal canvasWidth() const;
    void setCanvasWidth(qreal w);

    qreal canvasHeight() const;
    void setCanvasHeight(qreal h);

    qreal renderWidth() const;
    qreal renderHeight() const;

public slots:
    void saveImage(const QUrl &url);
    void copyToClipboard();

signals:
    void canvasWidthChanged();
    void canvasHeightChanged();

    void renderWidthChanged();
    void renderHeightChanged();

private:
    void setRenderHeight(qreal h);
    void setRenderWidth(qreal w);

    QColor m_foreground;
    QColor m_background;
    QImage m_canvas;

    qreal m_renderWidth;
    qreal m_renderHeight;
};

#endif // SCREENCANVAS_H