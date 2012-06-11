#ifndef QXMESHDEF_H
#define QXMESHDEF_H

#include <QPolygonF>
#include <QList>
#include <QImage>
#include "qxmesh.h"
#include "qxmesh_global.h"

class QXMESH_API QxMeshDef
{
public:
  QxMeshDef();

  QxMeshDef(const QPolygonF &boundary,
            const QList<QPolygonF> &holes = QList<QPolygonF>(),
            const QVector<QPointF> &points = QVector<QPointF>());

  QxMeshDef(const QxMeshDef &other);

  QxMesh mesh() const;

  void simplify(uint vertices);

  void offset(qreal pixels);

  static QList<QxMeshDef> fromImage(const QImage &image);

  QPolygonF boundary;
  QList<QPolygonF> holes;
  QVector<QPointF> points;
};

#endif // QXMESHDEF_H
