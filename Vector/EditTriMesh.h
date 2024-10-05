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
	void empty();
	void setTriCount(int tc);
	void setVertexCount(int vc);
	int addTri();//����������
	int addTri(const Tri& t);
	int addVertex();//���Ӷ���
	int addVertex(const Vertex& v);
private:
	int vAlloc;
	int vCount;
	Vertex* vList;
	int tAlloc;
	int tCount;
	Tri* tList;

	void construct();
};