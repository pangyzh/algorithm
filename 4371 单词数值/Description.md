# [第十九周]单词数值

### 题目描述
小明喜欢发短信，一天他突然想出一种定义短信中单词的值的方法，也许能够揭示某种规律。

小明的手机键盘如下图所示：

![](http://222.200.185.45/UserFiles/smiedsa/%E5%9B%BE%E7%89%875.png)

输入法为字母输入，即每次输入一个字母，例如需要输入字母x，由于x在数字键9上，排在第二位，因此需要按下9键两次。

小明定义单词的值如下：单词中每个字母（不区分大小写）的值等于**按键数值与按键次数之积**，单词的值等于所有字母的值之和。如单词word的值为9+6*3+7*3+3=51。

### 输入格式
第一行给出单词数T（1<=T<=100,000）。

接下来T行，每行一个单词，单词最大长度不超过100。

### 输出格式
输出T行，每行为单词的对应值。

### 样例输入
```
3
Word
I
Day
```

### 样例输出
```
51
12
32
```