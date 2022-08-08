// FOR DIRECTED AND UNDIRECTED GRAPHS!!!

#ifndef ADJLIST_H
#define ADJLIST_H

struct edge;

struct vertex
{
	int data;
	struct vertex*nextVertex;
	struct edge*firstEdge;
};

typedef struct vertex vertex;

struct edge
{
	vertex*dstVertex;
	struct edge*nextEdge;
};

typedef struct edge edge;

/* --- function to search for a vertex --- */
vertex*searchVertex(vertex*vtx, int val)
{
	if(vtx==NULL)
	{
		printf("\n\ngraph has no vertices!\n\n");
		return vtx;
	}

	while(vtx!=NULL && vtx->data!=val)
		vtx=vtx->nextVertex;

	if(vtx==NULL)
		return vtx;

	return vtx;
}
/* --- <END> --- */

/* --- functions for performing vertex insertion and vertex deletion --- */
vertex*insertVertex(vertex*vtx,vertex*cvtx, int val)
{
	if(vtx==NULL)
	{
		vtx=(vertex*)malloc(sizeof(vertex));
		vtx->data=val;
		vtx->nextVertex=NULL;
		vtx->firstEdge=NULL;

		return vtx;
	}


	if(searchVertex(cvtx, val)!=NULL)
	{
		printf("\n%d already exists in the graph!!\n\n", val);
		return vtx;
	}

	vtx->nextVertex=insertVertex(vtx->nextVertex, cvtx, val);

	return vtx;
}

vertex*delVertex(vertex*vtx, int val)
{
	if(vtx==NULL)
	{
		printf("\n\nthe graph has no vertices!!\n\n");
		return vtx;
	}

	// STEP 1: search val in the vertex list
	vertex*tV=searchVertex(vtx, val);

	if(tV==NULL)
	{
		printf("\n\nINVALID VERTEX!!\n\n");
		return vtx;
	}

	// STEP 2: remove tV from the edge list from every vertex(if it exists in them)
	vertex*tmv=vtx;
	edge*tE=NULL, *pE=NULL;

	while(tmv!=NULL)
	{
		pE=NULL;
		if(tmv->firstEdge==NULL) // tmv doesnot have an edge list
		{
			tmv=tmv->nextVertex;
			continue;
		}

		tE=tmv->firstEdge;

		while(tE!=NULL && tE->dstVertex!=tV)
		{
			pE=tE;
			tE=tE->nextEdge;
		}

		if(tE==NULL)
		{
			tmv=tmv->nextVertex;
			continue;
		}

		else if(pE==NULL) // the first edge of tmv contains tV 
		{
			if(tE->nextEdge==NULL) // tmv has only one edge
			{
				free(tE);
				tmv->firstEdge=NULL;
			}

			else
			{
				tmv->firstEdge=tE->nextEdge;
				free(tE);
			}
		}

		else if(tE->nextEdge==NULL) // last edge of tmv contains tV
		{
			pE->nextEdge=NULL;
			free(tE);
		}

		else
		{
			pE->nextEdge=tE->nextEdge;
			free(tE);
		}

		tmv=tmv->nextVertex;
	}

	// STEP 3: remove the edge list of tV
	
	if(tV->firstEdge==NULL) // tV doesnot have an edge list
	{
		if(tV==vtx) // tV is the first vertex to be deleted
		{
			vtx=vtx->nextVertex;

			free(tV);
		}

		else
		{
			tmv=vtx;
			while(tmv->nextVertex!=tV)
				tmv=tmv->nextVertex;

			tmv->nextVertex=tV->nextVertex;
			free(tV);
		}
	}

	else
	{
		tE=tV->firstEdge;

		while(tE!=NULL)
		{
			pE=tE;
			tE=tE->nextEdge;
			free(pE);
		}

		// STEP 4: remove tV from the vertex list
		
		if(tV==vtx) // tV is the first vertex to be deleted
		{
			vtx=vtx->nextVertex;
			free(tV);
		}

		else
		{
			tmv=vtx;
			while(tmv->nextVertex!=tV)
				tmv=tmv->nextVertex;

			tmv->nextVertex=tV->nextVertex;

			free(tV);
		}
	}

	return vtx;
}
/* --- <END> --- */

/* --- functions for insertion and deletion of edges --- */
vertex*insertEdgeU(vertex*vtx, int iv, int dv) // for undirected graph!!
{
	if(vtx==NULL)
	{
		printf("\n\ngraph has no vertices!!\n\n");
		return vtx;
	}

	vertex*vi=searchVertex(vtx, iv);
	vertex*vd=searchVertex(vtx, dv);


	if(vi==NULL)
	{
		if(vd==NULL)
		{
			printf("\n\n%d and %d donot exist in the graph, cannot insert edge!!\n\n", iv, dv);
			return vtx;
		}
		
		printf("\n%d is not in the graph, cannot insert edge!!\n", iv);
		return vtx;
	}

	if(vd==NULL)
	{
		if(vd==NULL)
		{
			printf("\n\n%d and %d donot exist in the graph, cannot insert edge!!\n\n", iv, dv);
			return vtx;
		}

		printf("\n%d is not in the graph, cannot insert edge!!\n", dv);
		return vtx;
	}

	// checking whether vi has an edge list or not!!
	if(vi->firstEdge==NULL)
	{
		edge*te;
		te=(edge*)malloc(sizeof(edge));
		te->dstVertex=vd;
		te->nextEdge=NULL;
		vi->firstEdge=te;

		// checking whether vd has an edge list or not!!
		if(vd->firstEdge==NULL) // destination vertex also doesnot have an edge list
		{
			te=(edge*)malloc(sizeof(edge));
			te->dstVertex=vi;
			te->nextEdge=NULL;
			vd->firstEdge=te;
		}

		else
		{
			te=vd->firstEdge;
			edge*pe=NULL;

			while(te!=NULL && te->dstVertex!=vi)
			{
				pe=te;
				te=te->nextEdge;
			}

			if(te==NULL)
			{
				te=(edge*)malloc(sizeof(te));
				te->dstVertex=vi;
				te->nextEdge=NULL;
				pe->nextEdge=te;
			}
		}
	}

	else // initial vertex has an edge list
	{
		edge*te=vi->firstEdge, *pe=NULL;

		while(te!=NULL && te->dstVertex!=vd)
		{
			pe=te;
			te=te->nextEdge;
		}

		if(pe==NULL) // first edge of vi contains vd as destination vertex!!
		{
			printf("\nedge (%d,%d) already exists in the graph!!\n\n", iv, dv);
			return vtx;
		}

		else if(te==NULL)
		{
			te=(edge*)malloc(sizeof(edge));
			te->dstVertex=vd;
			te->nextEdge=NULL;
			pe->nextEdge=te;

			// making vi the destination vertex of vd(since it's an undirected graph, vi-vd is same as vd-vi)
			// in an undirected graph, if vd exists in the edge list of vi then vice versa is also true!!

			if(vd->firstEdge==NULL)
			{
				te=(edge*)malloc(sizeof(edge));
				te->dstVertex=vi;
				te->nextEdge=NULL;
				vd->firstEdge=te;
				return vtx;
			}

			te=NULL;
			te=vd->firstEdge;
			pe=NULL;

			while(te!=NULL && te->dstVertex!=vi)
			{
				pe=te;
				te=te->nextEdge;
			}

			if(te==NULL)
			{
				te=(edge*)malloc(sizeof(edge));
				te->dstVertex=vi;
				te->nextEdge=NULL;
				pe->nextEdge=te;
			}

		}


	}

	return vtx;
}

vertex*insertEdgeD(vertex*vtx, int iv, int dv) // directed graph
{
	if(vtx==NULL)
	{
		printf("\n\nthe graph has no vertices!!\n\n");
		return vtx;
	}

	vertex*vi=searchVertex(vtx, iv);
	vertex*vd=searchVertex(vtx, dv);

	if(vi==NULL)
	{
		if(vd==NULL)
		{
			printf("\n\n%d and %d donot exist in the graph, cannot insert edge!!\n\n", iv, dv);
			return vtx;
		}
		
		printf("\n%d is not in the graph, cannot insert edge!!\n", iv);
		return vtx;
	}

	if(vd==NULL)
	{
		if(vi==NULL)
		{
			printf("\n\n%d and %d donot exist in the graph, cannot insert edge!!\n\n", iv, dv);
			return vtx;
		}

		printf("\n%d is not in the graph, cannot insert edge!!\n", dv);
		return vtx;
	}

	// whether vi has edge list or not!!
	
	if(vi->firstEdge==NULL)
	{
		edge*te=(edge*)malloc(sizeof(edge));
		te->dstVertex=vd;
		te->nextEdge=NULL;
		vi->firstEdge=te;

		return vtx;
	}

	else
	{
		edge*te=vi->firstEdge, *pe=NULL;

		while(te!=NULL && te->dstVertex!=vd)
		{
			pe=te;
			te=te->nextEdge;
		}

		if(te==NULL)
		{
			te=(edge*)malloc(sizeof(edge));
			te->dstVertex=vd;
			te->nextEdge=NULL;
			pe->nextEdge=te;
		}

		else if(pe==NULL)
		{
			printf("\n\nedge (%d,%d) already exists in the graph!!\n\n", iv, dv);
			return vtx;
		}

		else
		{
			printf("\n\nedge (%d,%d) already exists in the graph!!\n\n", iv, dv);
			return vtx;
		}
	}

	return vtx;
}


vertex*delEdgeU(vertex*vtx, int iv, int dv) // undirected graph
{
	if(vtx==NULL)
	{
		printf("\nthe graph has no vertices!!\n\n");
		return vtx;
	}

	vertex*vi=searchVertex(vtx, iv);
	vertex*vd=searchVertex(vtx, dv);

	if(vi==NULL)
	{
		if(vd==NULL)
		{
			printf("\n\n%d and %d donot exist in the graph, cannot delete edge!!\n\n", iv, dv);
			return vtx;
		}
		
		printf("\n%d is not in the graph, cannot delete edge!!\n", iv);
		return vtx;
	}

	if(vd==NULL)
	{
		if(vd==NULL)
		{
			printf("\n\n%d and %d donot exist in the graph, cannot delete edge!!\n\n", iv, dv);
			return vtx;
		}

		printf("\n%d is not in the graph, cannot delete edge!!\n", dv);
		return vtx;
	}

	if(vi->firstEdge==NULL)
	{
		printf("\n\n%d is not the destination vertex of %d\n", dv, iv);
		printf("\n\n%d is also not the destination vertex of %d\n", iv, dv);
		printf("\nwrong edge!!\n\n");
		return vtx;
	}

	else
	{
		edge*te=vi->firstEdge, *pe=NULL;
		while(te!=NULL && te->dstVertex!=vd)
		{
			pe=te;
			te=te->nextEdge;
		}

		if(pe==NULL && te!=NULL) // first edge of vi contains vd
		{
			vi->firstEdge=te->nextEdge;
			free(te);

			// remove vi from vd's edge list

			te=vd->firstEdge;
			pe=NULL;

			while(te!=NULL && te->dstVertex!=vi)
			{
				pe=te;
				te=te->nextEdge;
			}

			if(pe==NULL) // first edge of vd contains vi
			{
				vd->firstEdge=te->nextEdge;
				free(te);
			}

			else
			{
				pe->nextEdge=te->nextEdge;
				free(te);
			}

			return vtx;
		}

		else
		{

			pe->nextEdge=te->nextEdge;
			free(te);

			// remove vi from vd's edgelist

			te=vd->firstEdge;
			pe=NULL;

			while(te!=NULL && te->dstVertex!=vi)
			{
				pe=te;
				te=te->nextEdge;
			}

			if(pe==NULL)
			{
				vd->firstEdge=te->nextEdge;
				free(te);
			}

			else
			{
				pe->nextEdge=te->nextEdge;
				free(te);
			}

			return vtx;
		}
	}


	return vtx;

}

vertex*delEdgeD(vertex*vtx, int iv, int dv) // directed graph
{
	if(vtx==NULL)
	{
		printf("\nthe graph has no vertices!!\n\n");
		return vtx;
	}

	vertex*vi=searchVertex(vtx, iv);
	vertex*vd=searchVertex(vtx, dv);

	if(vi==NULL)
	{
		if(vd==NULL)
		{
			printf("\n\n%d and %d donot exist in the graph, cannot delete edge!!\n\n", iv, dv);
			return vtx;
		}
		
		printf("\n%d is not in the graph, cannot delete edge!!\n", iv);
		return vtx;
	}

	if(vd==NULL)
	{
		if(vd==NULL)
		{
			printf("\n\n%d and %d donot exist in the graph, cannot delete edge!!\n\n", iv, dv);
			return vtx;
		}

		printf("\n%d is not in the graph, cannot delete edge!!\n", dv);
		return vtx;
	}

	if(vi->firstEdge==NULL)
	{
		printf("\n%d is not the destination vertex of %d\n", dv, iv);
		return vtx;
	}

	edge*te=vi->firstEdge, *pe=NULL;

	while(te!=NULL && te->dstVertex!=vd)
	{
		pe=te;
		te=te->nextEdge;
	}

	if(pe==NULL)
	{
		if(te->nextEdge==NULL) // vi has only the first edge
		{
			free(te);
			vi->firstEdge=NULL;
		}

		else
		{
			vi->firstEdge=te->nextEdge;
			free(te);
		}

		return vtx;
	}

	else
	{
		pe->nextEdge=te->nextEdge;
		free(te);
	}

	return vtx;
}
/* --- <END> --- */

/* --- function for displaying the graph --- */
void dispGraph(vertex*vtx)
{
	if(vtx==NULL)
	{
		printf("\n\ngraph has no vertices!!\n\n");
		return;
	}

	printf("\n\nADJACENCY LIST:\n\n");
	edge*te=NULL;
	while(vtx!=NULL) // vertex list
	{
		printf("%d->", vtx->data);
		te=vtx->firstEdge;
		while(te!=NULL) // edge list
		{
			printf("%d->", te->dstVertex->data);
			te=te->nextEdge;
		}
		
		printf("\n|\nv\n");

		vtx=vtx->nextVertex;
	}
}
/* --- <END> --- */

/* --- function to terminate all the vertices --- */
vertex*terminate(vertex*vtx)
{
	edge*te=NULL, *pe=NULL;
	vertex*pv=NULL;

	while(vtx!=NULL)
	{
		te=vtx->firstEdge;
		// delete all the edges of each vertex

		while(te!=NULL)
		{
			pe=te;
			te=te->nextEdge;
			free(pe);
		}

		pv=vtx;
		vtx=vtx->nextVertex;
		free(pv);
	}
}
/* --- <END> --- */
#endif
