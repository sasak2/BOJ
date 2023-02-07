# [Gold V] Bookend - 16465 

[문제 링크](https://www.acmicpc.net/problem/16465) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹(ad_hoc), 많은 조건 분기(case_work), 구현(implementation)

### 문제 설명

<p>최근 투자 실패로 전세 자금을 날려 먹은 준엽이는 여자친구와 방을 합치기로 했다. 부푼 마음을 가지고 이사를 하던 준엽이는 책장 앞에서 여자친구와 대립 중이다. 바로 깔끔하지 못한 여자친구의 책꽂이 습관 때문이다. 강박증이 심한 준엽이는 책장에 책이 비스듬히 세워지거나 옆으로 넘어지는 것을 원하지 않는다. </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/97c60197-3d5a-498e-8db1-6f5c983ae608/-/preview/" style="width: 400px;">     <img alt="" src="https://upload.acmicpc.net/d3c95ff8-7cf1-4391-8fa8-896ee58eeb65/-/preview/" style="width: 330px;"></p>

<p style="text-align: center;"><strong>준엽이가 좋아하지 않는 책장 상태</strong></p>

<p>준엽이는 ㄱ자 모양 북엔드를 몇 개 구매하여, 책들을 넘어지지 않게 고정하고 싶다. 준엽이는 책들의 위치와 배열에 상관없이, 어떤 책도 넘어지지 않고 양면이 지탱되고 있는 상태를 좋아한다. 당연하겠지만, 강박증이 있는 준엽이는 책들의 순서가 바뀌는 것을 좋아하지 않는다. 즉, 준엽이가 가져온 책들의 순서가 그대로 유지되어야 한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/de823e11-f170-44bc-95bd-326d609c3fad/-/preview/" style="width: 300px;">                   <img alt="" src="https://upload.acmicpc.net/d440cb08-d836-43e5-8e80-115087068786/-/preview/" style="height: 278px; width: 500px;"></p>

<p style="text-align: center;"><strong>북엔드 실물                                                                             준엽이가 좋아하는 책장 상태 </strong></p>

<p> </p>

<p>신나는 마음으로 북엔드를 구입한 준엽이는 당황했다. 북엔드의 바닥 면이 생각보다 컸던 것이다. 만약 두 개의 북엔드의 바닥 면을 겹쳐 놓으면 한쪽 북엔드가 기울어져서 보기 싫은 상태가 된다. 준엽이를 도와 책장을 깔끔하게 정리해 줄 북엔드의 최소 개수를 구해 주자. 북엔드는 충분히 크고 무거워서 책에 밀려 넘어지지 않는다고 가정한다.</p>

### 입력 

 <p>첫 번째 줄에 책의 개수 정수 N (1 ≤ N ≤ 100)과, 책장의 너비 정수 M (1 ≤ M ≤ 300), 북엔드의 바닥 면의 길이 정수 L (1 ≤ L ≤ 300)이 주어진다.</p>

<p>두 번째 줄에 각 책의 너비인 정수 x<sub>i</sub> (1 ≤ x<sub>i</sub> ≤ 3)가 왼쪽 책부터 차례대로 N개 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 준엽이가 좋아하는 책장 상태를 만드는 데 필요한 최소 북엔드의 개수를 출력한다. 만약 불가능하다면 -1을 출력한다. </p>

