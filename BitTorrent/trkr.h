/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _TRACKER_H_RPCGEN
#define _TRACKER_H_RPCGEN

#include <rpc/rpc.h>

extern int req_threshold;

#ifdef __cplusplus
extern "C" {
#endif

#define MAXHOSTNAME 32
#define MAXFILELEN 65535
#define MAXNAMELEN 255
#define MINNODES 4

struct file_data {
	char *filename;
	int file_size;
	int num_requests;
	int num_nodes;
	struct node *node_list_head;
	struct node *node_list_tail;
	struct file_data *next;
};
typedef struct file_data file_data;

struct two_nodes {
	char *hostname1;
	char *hostname2;
};
typedef struct two_nodes two_nodes;

struct node_file {
	char *filename;
	int file_size;
	struct node_file *next;
};
typedef struct node_file node_file;

struct node {
	char *hostname;
	struct node_file *node_file_head;
	struct node_file *node_file_tail;
	struct node *next;
};
typedef struct node node;

struct query_info {
	int file_size;
	int num_nodes;
	struct node *nodes;
};
typedef struct query_info query_info;

struct query_param {
	int caller;
	char *filename;
};
typedef struct query_param query_param;

#define TRACKER_PROG 0x20000003
#define TRACKER_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define NODE_LOOKUP_NEW 1
extern  two_nodes * node_lookup_new_1(char **, CLIENT *);
extern  two_nodes * node_lookup_new_1_svc(char **, struct svc_req *);
#define NODE_LOOKUP_QUERY 2
extern  query_info * node_lookup_query_1(query_param *, CLIENT *);
extern  query_info * node_lookup_query_1_svc(query_param *, struct svc_req *);
#define NODE_REGISTER 3
extern  int * node_register_1(char **, CLIENT *);
extern  int * node_register_1_svc(char **, struct svc_req *);
#define FILE_REGISTER 4
extern  int * file_register_1(node *, CLIENT *);
extern  int * file_register_1_svc(node *, struct svc_req *);
extern int tracker_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define NODE_LOOKUP_NEW 1
extern  two_nodes * node_lookup_new_1();
extern  two_nodes * node_lookup_new_1_svc();
#define NODE_LOOKUP_QUERY 2
extern  query_info * node_lookup_query_1();
extern  query_info * node_lookup_query_1_svc();
#define NODE_REGISTER 3
extern  int * node_register_1();
extern  int * node_register_1_svc();
#define FILE_REGISTER 4
extern  int * file_register_1();
extern  int * file_register_1_svc();
extern int tracker_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_file_data (XDR *, file_data*);
extern  bool_t xdr_two_nodes (XDR *, two_nodes*);
extern  bool_t xdr_node_file (XDR *, node_file*);
extern  bool_t xdr_node (XDR *, node*);
extern  bool_t xdr_query_info (XDR *, query_info*);
extern  bool_t xdr_query_param (XDR *, query_param*);

#else /* K&R C */
extern bool_t xdr_file_data ();
extern bool_t xdr_two_nodes ();
extern bool_t xdr_node_file ();
extern bool_t xdr_node ();
extern bool_t xdr_query_info ();
extern bool_t xdr_query_param ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_TRACKER_H_RPCGEN */
