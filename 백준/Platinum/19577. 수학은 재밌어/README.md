# [Platinum V] 수학은 재밌어 - 19577 

[문제 링크](https://www.acmicpc.net/problem/19577) 

### 성능 요약

메모리: 2088 KB, 시간: 0 ms

### 분류

수학, 정수론, 오일러 피 함수

### 제출 일자

2025년 6월 22일 14:30:40

### 문제 설명

<p>오일러는 수학을 정말 좋아해서 하루 종일 수학 공부만 하는 수학쟁이이다.</p>

<p>어느 날 오일러는 수학 공부를 하기 위해서 수학 책을 읽고 있던 중에 오일러 피 함수에 대해서 설명하는 부분을 보게 되었다. 오일러 피 함수는 다음과 같이 설명이 되어 있었다.</p>

<blockquote>
<p>오일러 피 함수란 <em>φ</em>(<em>n</em>)으로 표기하며 1부터 <em>n</em>까지의 양의 정수 중에서 <em>n</em>과 서로소인 수의 개수를 나타내는 함수이다.</p>

<p>예를 들면 <em>φ</em>(6)은 1부터 6까지의 수 중 6과 서로소인 수의 개수를 말하는데 이는 1과 5로 두 개가 있으므로 <em>φ</em>(6) = 2이다.</p>
</blockquote>

<p>오일러는 책의 내용을 곰곰이 읽던 중 어떤 문제가 떠올랐다. 문제의 내용은 다음과 같다.</p>

<blockquote>
<p>어떤 양의 정수 <em>n</em>이 있다고 할 때, <em>xφ</em>(<em>x</em>) = <em>n</em>을 만족하는 양의 정수 <em>x</em>가 존재하는가?</p>
</blockquote>

<p>고민에 빠진 오일러를 본 당신은 오일러의 궁금증을 해결해주기 위해서 직접 문제를 풀기로 결심했다. 그러므로 당신은 <em>xφ</em>(<em>x</em>) = <em>n</em>을 만족하는 <em>x</em>를 구하는 프로그램을 작성하면 된다.</p>

### 입력 

 <p>첫 번째 줄에 <em>n</em>이 입력으로 주어진다. (1 ≤ <i>n</i> ≤ 10<sup>9</sup>)</p>

### 출력 

 <p><em>xφ</em>(<em>x</em>) = <em>n</em>을 만족하는 양의 정수 <em>x</em>가 존재하면 최소의 <em>x</em>를, 존재하지 않으면 −1을 출력한다.</p>

