---
title: 可程式控制作業 電二乙 23 蔡丞銳
updated: 2022-05-08
---
<style type="text/css">
#DIV1{
width:300px;　//DIV區塊寬度
line-height:50px;　//DIV區塊高度
padding:20px;　//DIV區塊內距，參閱：CSS padding 內距。
margin-right:10px;　//靠右外距，參閱：CSS margin 邊界使用介紹範例教學。
float:left;
}
#DIV2{
width:300px;
line-height:50px;
padding:0px;
float:right;
}
</style>

# Self-Balance Robot
###### tags: `homework`

## 摘要
使用RPI pico最為控制器，控制只有兩輪的自平衡機器人，輪子的控制使用帶有旋轉編碼器的馬達進行伺服控制，使用陀螺儀+線性加速度感測器計算出重力，用以平衡機器人，還有前後各個一個的超音波感測器，避免遙控時撞到障礙物。
## 感測器
- ### 旋轉編碼器
    1. #### 說明:
        用來感測馬達轉速以進行PID控制
    2. #### 原理
        <div>
            <div id='DIV2'>
            <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQtYKmPEkXnFF3_QAE7_JX8TPgla-DLnaHBljE5l-BIE_R4gi3wm6cLVOKvg3vJbCWczng&usqp=CAU" width=250>
            </div>
            <div id='DIV1'>
                <br>
                <p>
                使用一片有許多洞的碼盤，鎖在馬達轉軸上，再使用LED和光電晶體感測光是否通過，藉此感測馬達的旋轉速度、角度及轉向。
                </p>
            </div>
        </div>  

    3. #### 感測器實體圖:
        <div>
        <img src="http://img.alicdn.com/imgextra/i3/1028072184/O1CN012kkgdQ1S0Jbdvh27D_!!1028072184.jpg" width=200> 
        </div>
    4. #### 其他使用方法
        - 作為賽車遊戲方向盤的角度感測器。
        - 用來偵測遙控車的轉向馬達位置，避免馬達燒壞。
- ### 陀螺儀+線性加速度感測器
    1. #### 說明  
        使用這兩種測器測出來的值計算出三個軸所受到的重力加速度，來保持機器人的平衡。
    2. #### 原理 
        {%youtube eqZgxR6eRjo %}
    3. #### 感測器實體圖
        <img src="https://img.ruten.com.tw/s1/2/37/57/21822102540119_869.jpg" width=150>
    4. #### 其他使用方法
        - 作為遙控飛機的姿態感測。
- ### 超音波距離感測器
    1. #### 說明  
        用來感測機器人前後是否有障礙物
    2. #### 原理  
        利用反射超音波計算發射和接收的時間差來算出和目標物之間的距離
    3. #### 感測器實體圖
        <img src="https://cf.shopee.tw/file/a0a1b2ac8bcb24f41030ef6a51f08faa" width=150>
    4. #### 其他使用方法 
        - 作為升降機構的高度感測器
        
## 心得與分享