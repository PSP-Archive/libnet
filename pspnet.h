#include <sys/types.h>

// Net Lib Helper - work in progress

// major functions - Access Point / NetInet
int nlhLoadDrivers();
int nlhInit();
int nlhTerm();

int sceNetInit(u32 r4, u32 r5, u32 r6, u32 r7, u32 r8);
int sceNetTerm();

int sceNetGetLocalEtherAddr(u8* addr);

int sceNetInetInit();
int sceNetInetTerm();

int sceNetResolverInit();
int sceNetResolverTerm();

int sceNetAdhocInit(); 
int sceNetAdhocctlInit(u32 r4, u32 r5, void* r6);
int sceNetAdhocTerm();
int sceNetAdhocctlConnect(const char*);

int sceNetApctlConnect(int profile);
int sceNetApctlInit(u32 r4, u32 r5);
int sceNetApctlTerm();
int sceNetApctlGetState(u32* stateOut);
int sceNetApctlGetInfo(u32 r4, void* r5);
int sceNetApctlDisconnect();

// socket layer - patterned after Berkeley/WinSock sockets 
// functions in this header can be used directly after init
// if you prefer,
//     you can #define them to the regular "socket()", "send()", "recv()" names

#define SOCKET int

SOCKET sceNetInetSocket(int af, int type, int protocol);
int sceNetInetSend(SOCKET s, const void* buf, int len, int flags);
int sceNetInetSendto(SOCKET s, const void* buf, int len, int flags,
                        const void* sockaddr_to, int tolen);
int sceNetInetConnect(SOCKET s, const void *name, int namelen);
int sceNetInetBind(SOCKET s, void *addr, int namelen);
int sceNetInetClose(SOCKET s);
int sceNetInetGetErrno();
int sceNetInetRecv(SOCKET s, u8* buf, int len, int flags);
int sceNetInetSelect(SOCKET s, fd_set *r, fd_set *w, fd_set *o, struct timeval *timeout);
int sceNetInetSetsockopt (SOCKET s, int level, int optname, const void *val, int len);

// for 'socket()'
#define AF_INET         2               /* internetwork: UDP, TCP, etc. */
#define SOCK_STREAM     1               /* stream socket */
#define SOCK_DGRAM      2               /* datagram socket */
#define TCP_NODELAY     0x0001
#define IPPROTO_TCP     6
#define IPPROTO_UDP     17
#define IPPROTO_IP      0

struct sockaddr {
        unsigned char sa_len;
        unsigned char sa_family;              /* address family */
            // REVIEW: is this correct?
        char    sa_data[14];            /* up to 14 bytes of direct address */
};
// Socket address, internet style.
struct sockaddr_in {
        unsigned char sin_len;
        unsigned char sin_family; // REVIEW: is this correct ?
        unsigned short sin_port; // use htons()
        unsigned char sin_addr[4];
        char    sin_zero[8];
};

#if 0
//REVIEW: flesh these in
int sceNetInetAccept(
int sceNetInetCloseWithRST(SOCKET s);
int sceNetInetGetpeername(
int sceNetInetGetsockname(
int sceNetInetGetsockopt(
int sceNetInetListen(
int sceNetInetPoll(
int sceNetInetRecvfrom(
int sceNetInetRecvmsg(
int sceNetInetSelect(
int sceNetInetSendmsg(
int sceNetInetSetsockopt(
int sceNetInetShutdown(
int sceNetInetSocketAbort(
int sceNetInetInetAddr(
int sceNetInetInetAton(
int sceNetInetInetNtop(
int sceNetInetInetPton(
#endif

// Other utilities
unsigned short htons(unsigned short wIn);
unsigned long htonl(unsigned long dwIn);

///////////////////////////////////////////////
