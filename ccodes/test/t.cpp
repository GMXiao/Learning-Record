
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: 考生实现代码
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
//简易dhcp服务器


#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include<queue>
using namespace std;

class MiniDhcpServer {
private:
    
public:
    queue<int> ip_reles;
    vector<bool> ipisused;
    vector<string> ip2mac;
    map<string,int> mac2ip;
    map<string,bool> macisonline;

    MiniDhcpServer():ipisused(256,0),ip2mac(256,""){
        for(int i = 0;i<256;i++){
            ip_reles.push(i);
        }
    }
    string findaNewIp(string mac){
        if(ip_reles.empty())return "NA";
        while (!ip_reles.empty() && ipisused[ip_reles.front()] == 1)
        {
            ip_reles.pop();
        }
        if(ip_reles.empty())return "NA";

        int ipformac = ip_reles.front();
        ip_reles.pop();

        ipisused[ipformac] = 1;
        ip2mac[ipformac] = mac;
        macisonline[mac] = 1;
        mac2ip[mac] = ipformac;
        return "192.168.0."+to_string(ipformac);
    }
    string Request(const string &mac)
    {
        //string rqmessage = "";
        //分配过且在线
        if(macisonline.find(mac)!=macisonline.end() && macisonline[mac] == 1){
            return "192.168.0."+to_string(mac2ip[mac]);
        }
        //分配过,不在线
        if(macisonline.find(mac)!=macisonline.end() && macisonline[mac] == 0){
            int preip = mac2ip[mac];
            //之前使用过的ip未被占用
            if(!ipisused[preip]){
                ipisused[preip] = 1;
                ip2mac[preip] = mac;
                //mac2ip[mac] = preip;
                macisonline[mac] = 1;
                return "192.168.0."+to_string(preip);
            }else{//之前ip被占用
                return findaNewIp(mac);
            }
        }
        //mac未分配过
        if(macisonline.find(mac)==macisonline.end()){
            return findaNewIp(mac);
        }
    }

    void Release(const string &mac)
    {
        if(macisonline.find(mac) == macisonline.end() || macisonline[mac] == 0){
            return;
        }
        int nowip = mac2ip[mac];
        ip_reles.push(nowip);
        ipisused[nowip] = 0;
        macisonline[mac] = 0;
    }
};

int main()
{
    int line;
    cin >> line;

    MiniDhcpServer dhcp;
    for (int loop = 0; loop < line; loop++) {
        string str;
        cin >> str;
        string opration = str.substr(0, str.find_first_of("="));
        string mac = str.substr(str.find_first_of("=") + 1);

        if (opration == "REQUEST") {
            cout << dhcp.Request(mac) << endl;
        } else if (opration == "RELEASE") {
            dhcp.Release(mac);
        }
    }

    return 0;
}
