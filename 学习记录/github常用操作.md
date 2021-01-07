### 创建新分支并同步到远程
* 查看本地分支：git branch
* 查看远程分支：git branch -a (remotes开头的是远程分支)
* 本地创建分支并切换到该分支: git checkout -b newbranch (等价于 git branch newbranch + git checkout newbranch)
* 提交本地分支数据到远程分支：git push origin newbranch:newbranch (一般当前如果不在该分支时，使用这种方式提交。如果当前在 branch_abc 分支下，也可以直接提交git push)
* 关联远程分支（建立本地到上游（远程）的链接）：git push --set-upstream-to=origin/ipfs070

### 合并分支并删除临时分支
* 在dev分支上进行了修改之后···
* 切回主分支 git checkout master
* 合并dev内容到master：git merge dev （将指定分支合并到当前分支）
* 删除分支dev git branch -d dev