#include <QxMeshDef>
#include <QxPotrace>
#include <QxPSimpl>
#include <QxClipper>

QxMeshDef::QxMeshDef()
{

}

QxMeshDef::QxMeshDef(const QPolygonF &boundary,
                     const QList<QPolygonF> &holes,
                     const QVector<QPointF> &points) :
  boundary(boundary),
  holes(holes),
  points(points)
{

}

QxMeshDef::QxMeshDef(const QxMeshDef &other) :
  boundary(other.boundary),
  holes(other.holes),
  points(other.points)
{

}

QxMesh QxMeshDef::mesh() const
{
  QxMesh mesh;

  return mesh;
}

void QxMeshDef::simplify(uint vertices)
{
  QxPSimpl::simplifyDouglasPeuckerN(boundary, vertices);
}

void QxMeshDef::offset(qreal pixels)
{
  boundary = QxClipper::offseted(boundary, pixels);
}

QList<QxMeshDef> QxMeshDef::fromImage(const QImage &image)
{
  QxPotrace potrace;
  if(!potrace.trace(image))
    return QList<QxMeshDef>();

  QList<QxMeshDef> defs;
  foreach(const QxPotrace::Polygon &polygon, potrace.polygons())
  {
    defs << QxMeshDef(polygon.boundary, polygon.holes);
  }
  return defs;
}
