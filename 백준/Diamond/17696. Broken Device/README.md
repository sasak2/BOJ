# [Diamond I] Broken Device - 17696 

[문제 링크](https://www.acmicpc.net/problem/17696) 

### 성능 요약

메모리: 13808 KB, 시간: 336 ms

### 분류

애드 혹(ad_hoc), 구성적(constructive), 수학(math)

### 문제 설명

<p>Anna and Bruno are archaeologists. They are investigating ruins in Iran.</p>

<p>Their tasks are as follows: Anna visits ruins and discovers artifacts, and Bruno analyzes the results in the base camp.</p>

<p>Their investigation is scheduled for Q(= 1 000) days. Every day, Anna sends the results to Bruno using a communication device. The results for each day is expressed as an integer X.</p>

<p>Anna can use the communication device once per day only. It can send a sequence of length N(= 150) consisting of 0 or 1.</p>

<p>However, it was broken. There are several broken places in the sequence of length N. For a broken place, it always sends the value 0 regardless of the actual set value. When Anna sends a sequence, she can see the positions of the broken places. But, Bruno does not know them. The positions of broken places and the number of broken places can change every day.</p>

<p>There is a danger that their investigation will be delayed. Because you are a candidate of a contestant of an international programming contest in Iran, Anna and Bruno ask you to write a program which sends the results of their investigation.</p>

<p>Write two programs which achieve the communication between Anna and Bruno.</p>

<ul>
	<li>Given the length of the sequence N, the integer to be sent X, the number of broken places K, and the positions of broken places P, the first program sets the sequence S sent by Anna.</li>
	<li>Given the sequence A received by Bruno, the second program recovers the integer X.</li>
</ul>

<p>At a place where the communication device works, the sequence S and the sequence A have the same value. At a broken place, the sequence A always has the value 0 regardless of the values of the sequence S .</p>

### 입력 

 <p>The sample grader reads the following data from the standard input.</p>

<ul>
	<li>The first line contains an integer Q.</li>
	<li>Then, information of Q queries are given.</li>
	<li>Information of each query consists of two lines as follows.
	<ul>
		<li>The first line contains three space separated integers N, X, K. This means the length of the sequence to be sent is N, the integer to be sent by Anna is X, and there are K broken places.</li>
		<li>The second line contains K space separated integers P<sub>0</sub>, P<sub>1</sub>, · · · , P<sub>K−1</sub>. This means, for each i (0 ≤ i ≤ K − 1), the P<sub>i</sub>-th place in the sequence is broken.</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>When the program terminates successfully, the sample grader writes the following information to the standard output. (The quotation mark is not written actually.)</p>

<ul>
	<li>If your program is considered as Wrong Answer, the sample grader writes its type in the following form “<code>Wrong Answer [1]</code>,” and your program is terminated.</li>
	<li>If every function call to <code>Anna</code> is not considered as Wrong Answer, the sample grader writes “<code>Accepted</code>” and the value of L<sup>∗</sup>. For the value of L<sup>∗</sup>, see Scoring.</li>
</ul>

<p>If your program is considered as several types of Wrong Answer, the sample grader reports only one of them.</p>

