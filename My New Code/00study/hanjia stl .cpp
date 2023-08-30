#include<bits/stdc++.h>

//序列式容器
//向量vector
//数组array
//双端队列deque         双端都可高效增加元素的顺序表
//列表list              双向遍历的链表
//单项列表forward_list  单方向遍历的链表

//关联式容器
//集合set          有序储存互异元素的容器（由节点组成的红黑树）
//多重集合multiset  有序储存元素，允许存在相等的元素
//映射map          由{键，值}对组成的集合，以某种比较键大小关系的谓词排列
//多重映射multimap  允许键有相等情况的映射

//无序(关联式)容器
//无序(多重)集合 unordered_set/unordered_multiset 只关心元素是否存在，使用哈希实现
//无序(多重)映射 unordered_map/unordered_multimap 同

//容器适配器
//适配器是使一种事物的行为类似于另外一种事物行为的一种机制
//适配器对容器进行包装，使其表现出另外一种行为。不是容器
//栈stack 后进先出(LIFO)的容器，对(deque)的包装
//队列queue 先进先出(FIFO)的容器，对(deque)的包装
//优先队列(priority_queue)元素次序由作用于所储存的值对上的某种谓语决定的队列，对(vector)的包装

//共有函数
// = 有赋值运算符及复制构造函数
// begin()返回开头元素的迭代器
// end()返回指向末尾的下一元素的迭代器 末尾元素的后继
// size()返回容器内的元素个数
// max_size()返回容器理论上能储存的最大元素个数
// empty()返回容器是否为空
// swap()交换两个容器
// clear()清空容器
// ==/！=//<//>//<=//>= 按字典序比较容器大小

//迭代器(Iterator)
//迭代器可看作一个数据指针 
//两个运算符 两个自增(++)和解引用(*)
// vector<int> data(10)
// for(int i=0;i<data.size();i++)
// for(auto i:data) 不改变迭代对象的值
// for(auto &i:data) i是一个引用，可以改变迭代对象值

// vector

//访问
//v.at(pos) v[pos]
//v.front(); 首元素的引用
//v.back();  尾元素的引用
//v.data();  返回第一个元素的指针
//迭代器
//begin()/cbegin()  *begin()=front
//end()/cend() 返回指向数组尾端占位符的迭代器，没有元素
//rbegin()/crbegin() 返回指向逆向数组首元素的逆向迭代器
//rend()/crend() 返回指向逆向数组末元素后一位置的迭代器，没元素
//长度
//empty() 返回bool值 即v.begin()==v.end() true为空 false为非空
//size() 返回容器长度(元素数量) 即std::distance(v.begin(),v.end())
//resize() 改变vector的长度 多退少补
//max_size()
//容量
//reserve(n) 强迫容器的容量改变为含n个元素的状态，如果n比容量小就不改变
//capacity() 返回容器容量最大
//shrink_to_fit() 使vector容量与长度一致
//增删
//clear() 清除所有元素
//insert() 在某个迭代器插入 与pos距离末尾长度成线性
//erase() 删除某个迭代器或者区间的元素
//push_back() 在最后添加一个元素
//pop_back() 删除末尾元素
//swap() 与另一个容器进行交换 常数复杂度

//set

// 红黑树实现 与集合相似 有相同元素用multiset
//在贪心算法中经常会需要出现类似 找出并删除最小的大于等于某个值的元素
//这种操作能轻松地通过 set 来完成

//插入与删除
//insert(x) 当容器中没有等价元素时，将x插入到set中
//erase(x) 删除值为x的所有元素 返回删掉元素的个数
//erase(pos) 删除迭代器为pos的元素
//erase(first,last) 删除[first,last)范围元素
//clear() 清空set

//迭代器 同上

//查找
//count(x) 返回set内键为x的元素数量
//find(x) 在set内存在键为x的元素时会返回该元素迭代器，否则为end()
//lower_bound(x) 返回指向首个不小于给定键的元素的迭代器 不存在返回end()
//upper_bound(x) 返回指向首个大于给定键的元素的迭代器 不存在返回end()
//empty() 返回容器是否为空
//size() 返回容器内元素个数

//map

//有序键值对容器 元素唯一
//map<Key,T> Key是键的类型 T是值的类型
//在搜索中，有时需要存储一些较为复杂的状态（如坐标，无法离散化的数值，字符串等）
//以及与之有关的答案（如到达此状态的最小步数）

//插入删除
//erase(key) 删掉键位key的所有元素 返回删除元素的数量
//erase(pos) 删掉迭代器为pos的元素
//erase(first,last)
//clear() 清空容器
//insert()
//下标访问如mp["Alan"]=100 进行查询或插入
//但注意下标访问时，如map中无相应键的元素，会自动插入新元素，设为默认值(对整数为0)
//频繁访问下标会出现大量无意义元素，影响map效率

//查询操作
//count(x) 返回容器内键为x的元素数量
//find(x) 若容器内存在键为x的元素 返回元素迭代器 否则返回end()
//lower_bound(x)
//upper_bound(x) 返回指向首个大于给定键的迭代器
//empty() 返回容器是否为空
//size() 返回容器内元素个数

//priority_queue

//std::priority_queue<TypeName> q;             // 数据类型为 TypeName
//std::priority_queue<TypeName, Container> q;  // 使用 Container 作为底层容器
//std::priority_queue<TypeName, Container, Compare> q;
// 使用 Container 作为底层容器，使用 Compare 作为比较类型
// 默认使用底层容器 vector
// 比较类型 less<TypeName>（此时为它的 top() 返回为最大值）
// 若希望 top() 返回最小值，可令比较类型为 greater<TypeName>
// 注意：不可跳过 Container 直接传入 Compare

//top() 访问堆顶元素
//empty() 查询是否为空
//size() 查询容器元素数量
//push(x) 插入x 并对底层容器排序
//pop() 删除堆顶元素

//STL算法

// find()顺序查找
// find_end()逆序查找
// reverse() 翻转数组
// unique() 去除容器中相邻的重复元素 与sort可实现容器去重
// sort() 排序 sort(v.begin(),v.v.end(),cmp) sort(a+begin(),a+end(),cmp)
// stable sort() 排序 保证原本的相对次序在排序后保持不变
// nth_element() 与sort格式同 找出范围 序列中第n大的元素
// binary_search() 二分查找
// merge(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3)) 
// 把俩(已排序)序列有序合并到第三个序列的插入迭代器
// inplace_merge() 将两个(已按小于运算符排序的):
// [first,middle),[middle,last)范围原地合并为一个有序序列
// lower_bound() 二分查找 指向第一个大于等于x的元素的位置的迭代器 否则返回end()
// upper_bound() 二分查找 指向第一个大于x的元素的位置的迭代器 否则返回end()
// 正常的 lower_bound(s.begin(),s.end())时O(n)
// 但set等关联式容器封装了 lower_bound 等函数 (像 s.lower_bound(val))是O(logn)
// next_permutation() 将当前排列更改为全排列的下一个排列
// 如果已是全排列最后一个(元素完全从大到小) 返回false 并改为第一个(从小到大)
// partial_sum 求前缀和 设源容器为x 目标容器为y 令y[i]=x[0]+……+x[i]
// partial_sum(src.begin(),src.end(),back_inserter(dst))

// string

// 动态分配内存 直接使用 cin>>s 输入 但速度较慢
// 重载了加法运算符与比较运算符 可按字典序比较 可用 sort 对若干字符串排序
// s.c_str()是转化为char指针 用来printf("%s",s.c_str())
// s.size() s.length() 返回string长度
// s.find() 寻找某字符(串)第一次出现的位置 find('t') find(t) find(u,pos)自pos位置起
// 没有出现 返回 string::npos 被定义为-1 但类型为 size_t
// substr(pos,len) 返回从pos位置开始截取最多len个字符组成的字符串
// insert(index,count,ch) insert(index,str) 在index位置插入count次字符串ch与str
// erase(index,count) 将字符串index位置开始(含)的count个字符删除
// replace(pos,count,str) replace(first,last,str)

// pair

// 类模板 将两个变量关联在一起 组成一个对
// 需要将关联数据捆绑储存、处理的场景

// 初始化
// pair<int,double> p0(1,2.0);  p1.first=1; p1.second=2.0;
// pair<int,doublr> p2=make_pair(1,2.0);
// auto p3=make_pair(1,2.0);
// 访问通过 p.first p.second

// 比较
// 先比较第一个变量 相等时再比较第二个变量
// 定义了比较运算符 可以与其它STL函数或数据结构配合
// priority_queue<pair<int,double>>q;

// 赋值
// p0=p1; swap(p0,p1); p2.swap(p3);

// 应用
// 离散化 把原始值作为first 原始数据位置作为second 将原始数据值排名赋给原本位置
// Dijkstra 单源最短路径问题
// pair map 很多情况 map 中储存的键值对通过 pair 向外暴露
// map<int,double>m; m.insert(make_pair(1,2.0));