---
title: 可程式控制作業 電二乙 23 蔡丞銳
updated: 2022-05-08
---

# Self-Balance Robot
###### tags: `homework`

## 摘要
一個只有兩輪，可以自動保持平衡和自動壁障的機器人

## 感測器
- ### 旋轉編碼器
    1. #### 說明:
    使用一片有許多洞的碼盤，鎖在馬達轉軸上，再使用LED和光電晶體感測光是否通過，藉此感測馬達的旋轉速度、角度及轉向。
    <div>
    <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQtYKmPEkXnFF3_QAE7_JX8TPgla-DLnaHBljE5l-BIE_R4gi3wm6cLVOKvg3vJbCWczng&usqp=CAU">
    </div>
    
    2. #### 感測器實體圖:
        <img src="http://img.alicdn.com/imgextra/i3/1028072184/O1CN012kkgdQ1S0Jbdvh27D_!!1028072184.jpg" width=150> 
- ### 陀螺儀+線性加速度感測器
    1. #### 說明  
        {%youtube eqZgxR6eRjo %}  
    2. #### 感測器實體圖
        <img src="https://img.ruten.com.tw/s1/2/37/57/21822102540119_869.jpg" width=150>
        
- ### 超音波距離感測器
    1. #### 說明  
        利用反射超音波計算發射和接收的時間差來算出和目標物之間的距離
    2. #### 感測器實體圖
        <img src="https://www.mouser.tw/images/marketingid/2019/img/177109536.png" width=300>
