# MyTestMacros



自己在写MFC程序的时候为了方便测试做的，因为VERIFY()的输出没有实际值，以及变量名什么的（其实主要是为了想能够Release运行的时候也可以输出错误，比较好测试），不知道大家是怎么做的，有没有更好的办法

* 可以类似vs异常那样的弹窗，但是依赖`afx.h`
* 不依赖`afx.h`也可以，但是我还不知道错误信息要怎么输出

## 包括的宏

* VERIFY_EQUAL(a, b)
* VERIFY_GREATER(a, b)
* VERIFY_LESS(a, b)
* VERIFY_GREATER_EQUAL(a, b)
* VERIFY_LESS_EQUAL(a, b)

其中a为标准值，b为待测变量  

## 示例

```c++
​```int var1 = 0;
VERIFY_EUQAL(0, var1 + 1);
​```
第一个参数为标准值，第二个参数为待测变量 
效果如图  
![test](.\test.png)  
    
    
其他几个宏也是类似用法


```