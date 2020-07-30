# led-matrix 방향지시등
플렉스 센서 구부러짐이 구부러짐이 설정 범위를 벗아나면 led-matrix와 lcd가 출력되는 장치이다.<br/>
플렉스 센서는 2개를 이용하였으며, 택트스위치를 이용하여 스위치가 HIGH인 상태에서만 입력센서가 <br/>
작동하도록 하였다.


1.구성장치

<img src="https://user-images.githubusercontent.com/53510936/88823468-14432880-d200-11ea-8065-2a93f1b51027.png" width="70%">


2.핀 배치도

<img src="https://user-images.githubusercontent.com/53510936/88824727-b0216400-d201-11ea-877b-d6fafa708fe8.png" width="60%">


3.기능구현
<br/><br/>
-택트스위치를 이용하여 led점등 설계


![image](https://user-images.githubusercontent.com/53510936/88868210-7fb1e800-d24a-11ea-8a40-f88119d9ad70.png)
<br/>
택트 스위치 상태가 HIGH일경우 LED는 점등되고 LOW일 경우 점등되지 않도록 한다.<br/>
택트 스위치는 누르는 것을 유지 할 필요없이 스위치를 누를 때마다 HIGH /LOW가 변환된다. 
<br/><br/>
-플렉스 센서로 lcd,led-matrix 출력
<br/><br/>
![image](https://user-images.githubusercontent.com/53510936/88835438-3a70c480-d210-11ea-9a74-879c9e5c34a9.png)               ![image](https://user-images.githubusercontent.com/53510936/88835494-4d839480-d210-11ea-8bd2-c6de86c48fb9.png)
<br/>
택트 스위치가 눌린 상태이며 LED 점등을 확인 후 플렉스 센서에 전위차를 이용해 if문을 사용하여 LCD와 도트 매트릭스에 원하는 값을 출력하도록 구현한다. 왼쪽 ,오른쪽 플렉스 센서에서 전위차가 if문에 만족되었을 때 LCD에서는 LEFT!!!또는 RIGHT!!!, 도트 매트릭스에서는 왼쪽 화살표 또는 오른쪽 화살표가 출력된다.
<br/><br/>

4.작동영상
<br/>
https://www.youtube.com/watch?v=cM4t-2mLPjU

 
