# Textile V2.0 开发
![开发计划](/pictures/textileV2.0开发.png "Thread V2.0开发计划")
## 目前已实现
* ThreadDB 管理

    ThreadDB 创建
    ThreadDB list
    ThreadDB 信息
    ThreadDB 修改信息

* 消息处理
    消息添加
    消息删除
    消息查找

* 节点管理
    添加
    删除
    角色更改
    查询角色

## ipfs peering 功能
ipfs0.6.0 版本引入了新的“peering”功能。 peering子系统可将go-ipfs配置到一组节点为“连接”，“保持连接”与“重新连接”。 节点可使用此子系统在常用节点之间创建“粘性”链接，以提高可靠性。

用例：

* 连接到IPFS群集的IPFS网关应建立节点连接，以确保网关始终可以从群集中获取内容。
* dapp可以使用一组固定服务或 textile cafe 对嵌入式go-ipfs节点进行对等。
* 一组朋友可以凝视以确保他们总是可以获取彼此的内容。