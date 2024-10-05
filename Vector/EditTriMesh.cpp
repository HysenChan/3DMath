#include"EditTriMesh.h"
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
void EditTriMesh::Vertex::setDefaults()
{
	memset(this, 0, sizeof(this));
}

void EditTriMesh::Tri::setDefaults()
{
	memset(this, 0, sizeof(this));
}

EditTriMesh::EditTriMesh()
{
	construct();
}

EditTriMesh::~EditTriMesh()
{
	empty();
}

void EditTriMesh::empty()
{
	if (vList != NULL)
	{
		::free(vList);
		vList = NULL;
	}
	vAlloc = 0;
	vCount = 0;

	if (tList != NULL)
	{
		::free(tList);
		tList = NULL;
	}
	tAlloc = 0;
	tCount = 0;
}

void EditTriMesh::setTriCount(int tc)
{
	assert(tc >= 0);
	assert(tCount <= tAlloc);
	if (tc > tCount)
	{
		if (tc > tAlloc)
		{
			tAlloc = tc * 4 / 3 + 10;
			tList = (Tri*)::realloc(tList, tAlloc * sizeof(*tList));
			if (tList == NULL)
			{
				printf("Out of memory\n");
			}
		}
		while (tCount < tc)
		{
			tList[tCount].setDefaults();
			++tCount;
		}
	}
	else
	{
		tCount = tc;
	}
}

void EditTriMesh::setVertexCount(int vc)
{
	assert(vc >= 0);
	assert(vCount <= vAlloc);
	if (vc > vCount)
	{
		if (vc > vAlloc)
		{
			vAlloc = vc * 4 / 3 + 10;
			vList = (Vertex*)::realloc(vList, vAlloc * sizeof(*vList));
			if (vList == NULL)
			{
				printf("Out of memory\n");
			}
		}
		while (vCount < vc)
		{
			vList[vCount].setDefaults();
			++vCount;
		}
	}
	else
	{
		vCount = vc;
	}
}

int EditTriMesh::addTri()
{
	int r = tCount;
	if (tCount >= tAlloc)
	{
		setTriCount(tCount + 1);
	}
	else
	{
		++tCount;
		tList[r].setDefaults();
	}
	return r;
}

int EditTriMesh::addTri(const Tri& t)
{
	int r = tCount;
	if (tCount >= tAlloc)
	{
		setTriCount(tCount + 1);
	}
	else
	{
		++tCount;
	}
	tList[r] = t;
	return r;
}

int EditTriMesh::addVertex()
{
	int r = vCount;
	if (vCount >= vAlloc)
	{
		setVertexCount(vCount + 1);
	}
	else
	{
		++vCount;
		vList[r].setDefaults();
	}
	return r;
}

int EditTriMesh::addVertex(const Vertex& v)
{
	int r = vCount;
	if (vCount >= vAlloc)
	{
		setVertexCount(vCount + 1);
	}
	else
	{
		++vCount;
	}
	vList[r] = v;
	return 0;
}

void EditTriMesh::construct()
{
	vAlloc = 0;
	vCount = 0;
	vList = NULL;
	tAlloc = 0;
	tCount = 0;
	tList = NULL;
}