#ifndef ADJ_H
#define ADJ_H

struct Edge; // forward declaration of structure Edge!!

struct Vertex
{
	int data;
	struct Vertex *nextVertex; // for the vertex list(next vertex next to the current vertex)
	struct Edge *firstEdge;  // for the edge list(the first edge of the current vertex)
};

typedef struct Vertex Vertex;

struct Edge
{
	struct Edge *nextEdge;
	struct Vertex *dstVertex;
};

typedef struct Edge Edge;

/* --- function for searching a vertex --- */
Vertex*searchVertex(Vertex*vtx, int value)
{
	if(vtx==NULL)
	{
		printf("\ngraph has no vertices!!\n\n");
		return vtx;
	}


	while(vtx!=NULL && vtx->data!=value)
		vtx=vtx->nextVertex;

	if(vtx==NULL)
	{
		printf("\ngraph has no vertex with value %d\n\n", value);
		return vtx;
	}

	return vtx;
}
/* --- <END> --- */

/* --- functions for vertex insertion and vertex deletion --- */
Vertex*insertVertex(Vertex*vtx, int value)
{
	if(vtx==NULL)
	{
		vtx=(Vertex*)malloc(sizeof(Vertex));
		vtx->data=value;
		vtx->nextVertex=NULL;
		vtx->firstEdge=NULL;

		return vtx;
	}

	vtx->nextVertex=insertVertex(vtx->nextVertex, value);

	return vtx;
}


Vertex*delVertex(Vertex*vtx, int value)
{
	if(vtx==NULL)
	{
		printf("\ngraph has no vertices!!\n\n");
		return vtx;
	}

	/* step 1: search for the vertex in the vertex list */

	Vertex*tempV=NULL;
	tempV=searchVertex(vtx, value);

	if(tempV==NULL)
	{
		printf("\ninvalid vertex!!!\n\n");
		return vtx;
	}


	/* step 2: search for the tempV in the edge list of each vertex and remove those edges in which tempV is the destination vertex*/
	Edge*tempE=NULL, *prevE=NULL;
	Vertex*tempV2=vtx;

	while(tempV2!=NULL) // looping through the vertex list
	{
		tempE=tempV2->firstEdge;

		while(tempE!=NULL && tempE->dstVertex!=tempV) // looping through the edgelist of the current vertex
		{
			prevE=tempE;
			tempE=tempE->nextEdge;
		}

		if(prevE==NULL && tempE==NULL) // tempV2 doesnot have an edge list!!
		{
			tempV2=tempV2->nextVertex;
			continue;
		}

		else if(prevE==NULL && tempE->dstVertex==tempV) // the first edge contains tempV
		{
			if(tempE->nextEdge==NULL) // tempV2 has only one edge!!
			{
				free(tempE);
				tempV2->firstEdge=NULL;
			}

			else
			{
				tempV2->firstEdge=tempE->nextEdge;
				free(tempE);
			}
		}

		else if(prevE!=NULL && tempE==NULL) // tempV doesnot exist in the edge list of tempV2
		{
			tempV2=tempV2->nextVertex; // proceed to the next vertex!!
			prevE=NULL;
			continue;
		}


		else if(prevE!=NULL && tempE->nextEdge==NULL) // the last edge contains tempV
		{
			prevE->nextEdge=NULL;
			free(tempE);
			prevE=NULL;
		}

		else
		{
			prevE->nextEdge=tempE->nextEdge;
			free(tempE);
		}

		tempV2=tempV2->nextVertex;
	}

	/* step 3: remove the edge list of tempV */

	tempE=tempV->firstEdge, *prevE;

	while(tempE!=NULL)
	{
		prevE=tempE;
		tempE=tempE->nextEdge;
		free(prevE);
	}

	/* step 4: remove tempV */

	tempV2=vtx;
	while(tempV2!=NULL && tempV2->nextVertex!=tempV)
		tempV2=tempV2->nextVertex;

	if(tempV==vtx && tempV->nextVertex==NULL) // the graph has only one vertex
	{
		free(tempV);
		vtx=NULL;
	}

	else if(tempV->nextVertex==NULL) // tempV is the last vertex
	{
		tempV2->nextVertex=NULL;
		free(tempV);
	}

	else if(tempV==vtx) // tempV is the first vertex
	{
		vtx=vtx->nextVertex;
		free(tempV);
	}

	else
	{
		tempV2->nextVertex=tempV->nextVertex;
		free(tempV);
	}


	return vtx;

}
/* --- <END> --- */


/* --- functions for edge insertion and edge deletion --- */
Vertex*insertEdge(Vertex*vtx, int intV, int dV)
{
	if(vtx==NULL)
	{
		printf("\nthe graph has no vertices!!\n\n");

		return vtx;
	}

	Vertex*vi=searchVertex(vtx, intV); // searching initial vertex in the vertex list
	Vertex*vd=searchVertex(vtx, dV); // searching final vertex in the vertex list

	if(vi==NULL)
	{
		if(vd==NULL)
		{
			printf("\n\ninitial and destination vertices donot exist in the graph; cannot insert edge!!\n\n");
			return vtx;
		}

		printf("\ninitial vertex doesnot exist in the graph; cannot insert edge\n\n");
		return vtx;
	}

	else if(vd==NULL)
	{
		if(vi==NULL)
		{
			printf("\n\ninitial and destination vertices donot exist in the graph; cannot insert edge!!\n\n");
			return vtx;
		}

		printf("\n\nfinal vertex doesnot exist in the graph; cannot insert edge\n\n");
		return vtx;
	}

	Edge*tempE=vi->firstEdge, *prevE=NULL;


	while(tempE!=NULL)
	{
		prevE=tempE;
		tempE=tempE->nextEdge;
	}

	if(prevE==NULL)
	{
		tempE=(Edge*)malloc(sizeof(Edge));
		tempE->dstVertex=vd;
		tempE->nextEdge=NULL;
		vi->firstEdge=tempE;
		return vtx;
	}

	tempE=(Edge*)malloc(sizeof(Edge));
	tempE->dstVertex=vd;
	prevE->nextEdge=tempE;
	tempE->nextEdge=NULL;

	return vtx;


}

Vertex*delEdge(Vertex*vtx, int intV, int dV)
{
	if(vtx==NULL)
	{
		printf("\n\ngraph has no vertices!!\n\n");
		return vtx;
	}

	Vertex*vi=searchVertex(vtx, intV);
	Vertex*vd=searchVertex(vtx, dV);

	if(vi==NULL)
	{
		if(vd==NULL)
		{
			printf("\n\ninitial and destination vertices donot exist in the graph; cannot delete edge!!\n\n");
			return vtx;
		}

		printf("\ninitial vertex doesnot exist in the graph; cannot delete edge\n\n");
		return vtx;
	}

	else if(vd==NULL)
	{
		if(vi==NULL)
		{
			printf("\n\ninitial and destination vertices donot exist in the graph; cannot delete edge!!\n\n");
			return vtx;
		}

		printf("\n\nfinal vertex doesnot exist in the graph; cannot delete edge\n\n");
		return vtx;
	}

	Vertex*temPV=vi;
	Edge*tempE=NULL, *prevE=NULL;

	if(vi->firstEdge==NULL) // vi doesnot have any edge list
	{
		printf("\n%d doesnot have an edgelist!!\n", vi->data);
		printf("\nfailed to delete %d\n\n", vd->data);
		return vtx;
	}

	tempE=vi->firstEdge;
	while(tempE!=NULL && tempE->dstVertex!=vd)
	{
		prevE=tempE;
		tempE=tempE->nextEdge;
	}

	if(prevE==NULL) // first edge of vi contains vd
	{
		if(tempE->nextEdge==NULL) // vi has only one edge
		{
			free(tempE);
			vi->firstEdge=NULL;
		}

		else
		{
			vi->firstEdge=tempE->nextEdge;
			free(tempE);
		}
	}

	else if(prevE!=NULL && tempE==NULL) // vd doesnot exist in the edge list of vi
	{
		printf("\n\n%d is not the final vertex of any edge of vertex %d\n\n", vd->data, vi->data);
		printf("\ncouldnot delete edge\n\n");
	}

	else if(tempE->nextEdge==NULL) // vd is the final vertex of vi's last edge
	{
		prevE->nextEdge=NULL;
		free(tempE);
	}

	else
	{
		prevE->nextEdge=tempE->nextEdge;
		free(tempE);
	}

	return vtx;
}
/* --- <END> --- */

/* --- function to display the graph --- */
void dispGraph(Vertex*vtx)
{
	if(vtx==NULL)
	{
		printf("\n\ngraph has no vertices!\n\n");
		return;
	}

	Edge*tempE;

	printf("\n\nADJACENCY LIST:\n\n");

	while(vtx!=NULL) // showing the vertex list
	{
		printf("%d->", vtx->data);
		tempE=vtx->firstEdge;
		while(tempE!=NULL) // showing the adjacency list of each vertex
		{
			printf("%d->", tempE->dstVertex->data);
			tempE=tempE->nextEdge;
		}

		printf("\n|\nv\n");

		vtx=vtx->nextVertex;
	}
}

/* --- free up memory space --- */
void terminate(Vertex*vtx)
{
	if(vtx==NULL)
		return;

	
	Vertex*tempV=vtx;
	Edge*tempE=NULL;

	// remove the adjacency list of each vertex
	while(tempV!=NULL)
	{
		while(tempV->firstEdge!=NULL)
		{
			tempE=tempV->firstEdge;
			tempV->firstEdge=tempV->firstEdge->nextEdge;
			free(tempE);
		}
		tempV=tempV->nextVertex;
	}

	// remove each vertex from the vertex list

	while(tempV!=NULL)
	{
		tempV=vtx;
		vtx=vtx->nextVertex;
		free(tempV);
	}

}
/* --- <END> ---- */
#endif
