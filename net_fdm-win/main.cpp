
#include <windows.h>

#include <ctime>
#include <iostream>
#include <string>

#include "net_fdm.hxx"

double htond(double x)	{
   int* p{reinterpret_cast<int*>(&x)};
   int tmp{p[0]};
   p[0] = htonl(p[1]);
   p[1] = htonl(tmp);
   return x;
}

float htonf(float x) {
   int* p{reinterpret_cast<int*>(&x)};
   *p = htonl(*p);
   return x;
}

SOCKET sendSocket = -1;
struct sockaddr_in sendAddr;

// IP and port where FG is listening
const std::string fg_ip{"127.0.0.1"};
const int fg_port{5500};

// period to update fg (in milliseconds)
const int update_period{1000};

void run();

int main(int argc, char** argv) {
   WSAData wd;
   if (WSAStartup(MAKEWORD(2,0),&wd) == 0) {
      memset(&sendAddr,0,sizeof(sendAddr));
      sendAddr.sin_family = AF_INET;
      sendAddr.sin_port = htons(fg_port);
      sendAddr.sin_addr.S_un.S_addr = inet_addr(fg_ip.c_str());
      sendSocket = socket(AF_INET,SOCK_DGRAM,0);
      if (sendSocket != INVALID_SOCKET) {
         run();
      } else {
         std::cout << "socket() failed" << std::endl;
      }
   } else {
      std::cout << "WSAStartup() failed" << std::endl;
   }
   return 0;
}

#define D2R (3.14159 / 180.0)

void run() {
   const double latitude{45.59823};      // degs
   const double longitude{-120.69202};   // degs
   const double altitude{150.0};         // meters above sea level
 
   float roll{};    // degs
   float pitch{};   // degs
   float yaw{};     // degs

   const float visibility{5000.0}; // meters

   while (true) {
      Sleep(update_period);

      FGNetFDM fdm;
      memset(&fdm,0,sizeof(fdm));
      fdm.version = htonl(FG_NET_FDM_VERSION);

      fdm.latitude  = htond(static_cast<double>(latitude * D2R));
      fdm.longitude = htond(static_cast<double>(longitude * D2R));
      fdm.altitude  = htond(static_cast<double>(altitude));

      fdm.phi   = htonf(static_cast<float>(roll * D2R));
      fdm.theta = htonf(static_cast<float>(pitch * D2R));
      fdm.psi   = htonf(static_cast<float>(yaw * D2R));

      fdm.num_engines = htonl(1);

      fdm.num_tanks = htonl(1);
      fdm.fuel_quantity[0] = htonf(100.0);

      fdm.num_wheels = htonl(3);

      fdm.cur_time = htonl(std::time(nullptr));
      fdm.warp = htonl(1);

      fdm.visibility = htonf(visibility);

      sendto(sendSocket, (char*)&fdm, sizeof(fdm), 0, (struct sockaddr*)&sendAddr, sizeof(sendAddr));

      roll += 5.0;      // increase roll in 5 degree increments
      if (roll > 20.0) {
         roll = 0.0;
      }
      std::cout << "Roll: " << roll << std::endl;
   }
}
