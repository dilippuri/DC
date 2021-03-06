/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALC_H_RPCGEN
#define _CALC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct calc_in {
	int x;
	int y;
	int z;
};
typedef struct calc_in calc_in;

#define CALC_P 0x34340000
#define CALC_V 1

#if defined(__STDC__) || defined(__cplusplus)
#define calc 1
extern  float * calc_1(calc_in *, CLIENT *);
extern  float * calc_1_svc(calc_in *, struct svc_req *);
extern int calc_p_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define calc 1
extern  float * calc_1();
extern  float * calc_1_svc();
extern int calc_p_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_calc_in (XDR *, calc_in*);

#else /* K&R C */
extern bool_t xdr_calc_in ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALC_H_RPCGEN */
