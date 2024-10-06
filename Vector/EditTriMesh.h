#pragma once
#include"Vector3.h"

class EditTriMesh
{
public:
	class Vertex
	{
	public:
		Vertex() { setDefaults(); }
		void setDefaults();

		Vector3 p;
		float u, v;
		Vector3 normal;
	};

	class Tri
	{
	public:
		Tri() { setDefaults(); }
		void setDefaults();
		struct Vert
		{
			int index;
			float u, v;
		};
		Vert v[3];
		Vector3 normal;

	private:
	};

	EditTriMesh();
	~EditTriMesh();

	int vertexCount() const { return vCount; }
	int triCount() const { return tCount; }

	Vertex& vertex(int vertexIndex);
	const Vertex& vertex(int vertexIndex)const;
	Tri& tri(int triIndex);
	const Tri& tri(int triIndex)const;

	void empty();
	void setTriCount(int tc);
	void setVertexCount(int vc);
	int addTri();//增加三角形
	int addTri(const Tri& t);
	int addVertex();//增加顶点
	int addVertex(const Vertex& v);

	void detachAllFaces();//面拆分

	void computeOneTriNormal(Tri& t);//计算三角形法向量
	void computeOneTriNormal(int triIndex);
	void computeTriNormals();//计算所有三角形法向量
	void computeVertexNormals();//计算所有顶点法向量
private:
	int vAlloc;
	int vCount;
	Vertex* vList;
	int tAlloc;
	int tCount;
	Tri* tList;

	void construct();
};