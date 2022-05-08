---
title: 可程式控制作業 電二乙 23 蔡丞銳
updated: 2022-05-08
---

# Self-Balance Robot
###### tags: `homework`

## 摘要
使用RPI pico最為控制器，控制只有兩輪的自平衡機器人，輪子的控制使用帶有旋轉編碼器的馬達進行伺服控制，使用陀螺儀+線性加速度感測器計算出重力，用以平衡機器人，還有前後各個一個的超音波感測器，避免遙控時撞到障礙物。
## 感測器
- ### 旋轉編碼器
    1. #### 說明:
    使用一片有許多洞的碼盤，鎖在馬達轉軸上，再使用LED和光電晶體感測光是否通過，藉此感測馬達的旋轉速度、角度及轉向。
    <div>
    <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQtYKmPEkXnFF3_QAE7_JX8TPgla-DLnaHBljE5l-BIE_R4gi3wm6cLVOKvg3vJbCWczng&usqp=CAU">
    </div>
    
    2. #### 感測器實體圖:
        <img src="http://img.alicdn.com/imgextra/i3/1028072184/O1CN012kkgdQ1S0Jbdvh27D_!!1028072184.jpg" width=150> 
    3. #### 其他使用方法
        - 作為賽車遊戲方向盤的角度感測器。
        - 用來偵測遙控車的轉向馬達位置，避免馬達燒壞。
- ### 陀螺儀+線性加速度感測器
    1. #### 說明  
        {%youtube eqZgxR6eRjo %}  
        使用這個感測器感測到的旋轉加速度，和線性加速度，計算出重力加速度。
    2. #### 感測器實體圖
        <img src="https://img.ruten.com.tw/s1/2/37/57/21822102540119_869.jpg" width=150>
    3. #### 其他使用方法
        - 作為遙控飛機的姿態感測。
- ### 超音波距離感測器
    1. #### 說明  
        利用反射超音波計算發射和接收的時間差來算出和目標物之間的距離
    2. #### 感測器實體圖
        <img src="https://cf.shopee.tw/file/a0a1b2ac8bcb24f41030ef6a51f08faa" width=150>
    3. #### 其他使用方法
        - 作為升降機構的高度感測器
        