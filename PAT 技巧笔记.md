# PAT 技巧笔记

+ cout 打印浮点数时固定位数

  ```cpp
            cout<<" "<<i<<" "<<setprecision(1);
            cout.setf(ios::fixed,ios::floatfield);
            cout<<poly[i];
  ```

+ while循环读取数据

  ```cpp
  while(scanf("%d",&n)!=EOF)
  ```
  
  

+ 定义长度为n的vector

  ```cpp
  vector<int> node(n)
  ```

  

+ Range-based for loop (since C++11)

  对xxx进行遍历，i为xxx中的元素

  https://en.cppreference.com/w/cpp/language/range-for

  ```cpp
  for(auto i:xxx)
  ```

  

+ vector 初始化

  ```cpp
  vector<int> window(k,28800)// 把window的k个元素初始化为28800
  ```

  

+ reverse 逆转函数

  ```cpp
  reverse(t.begin(), t.end());
  ```

  

