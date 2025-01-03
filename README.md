# **도서관 관리 시스템 구현**

- 책 제목으로 검색이 가능해야 합니다.
- 작가로 검색이 가능해야 합니다.
- 책 제목이 동일한 경우는 없다고 가정 합니다.
- 특정 책의 대여 여부를 알 수 있어야 합니다.
- 책의 이름으로 대여 여부를 검색하고 대여가 아닌 경우 대여할 수 있어야 합니다.
- 책의 작가로 대여 여부를 검색하고 대여가 아닌 경우 대여할 수 있어야 합니다.
- 책을 반납할 수 있어야 합니다.
- 모든 책의 재고는 난이도를 낮추기 위해 3권으로 통일 합니다.

![image](https://github.com/user-attachments/assets/32e80c37-4bad-4046-b32c-1ea2ead85010)


# 기능 구현

## 1. 책 등록

![image](https://github.com/user-attachments/assets/9384e159-4c89-45a7-b14d-fd413bf34016)

## 2. 책 목록 출력

![image](https://github.com/user-attachments/assets/ff89a43f-4ff6-47c7-b090-22a65a6abca0)

## 3. 책 대여

### 책 이름으로 대여

![image](https://github.com/user-attachments/assets/f67a2095-ca1d-4e20-930c-ec54cf723e35)

재고 확인을 하면 줄어 있다.

![image](https://github.com/user-attachments/assets/3c94d647-e43c-4318-9239-457fa278a264)

### 책 작가로 대여

![image](https://github.com/user-attachments/assets/1a76f9e5-2e5c-4fd4-aa40-106c6d381950)

대출된 모습.

![image](https://github.com/user-attachments/assets/d416f44c-056c-45a7-b1ef-ca1245722da9)

**예외 처리**

![image](https://github.com/user-attachments/assets/613db02d-365d-4e5e-8abb-3020843dfe68)

## 4. 책 반납

### 책 이름으로 반납

![image](https://github.com/user-attachments/assets/137f0b85-aae2-49c9-8b64-be7bc6359c6e)

반납된 모습.

![image](https://github.com/user-attachments/assets/e3c2a954-9e97-4249-9ec8-09b390d13b21)

**예외 처리**

![image](https://github.com/user-attachments/assets/eb1c0da9-47ee-4989-b14f-121d454cdd78)

이미 도서관에 재고가 꽉 찬 책인 경우 등록되지 않은 책이므로 다음을 출력한다. 

### 책 작가로 반납

![image](https://github.com/user-attachments/assets/8018fdf0-b371-4622-97d9-032e076fec71)

반납된 모습.

![image](https://github.com/user-attachments/assets/a82e5e22-4030-4e1e-bfa3-161f64d54c95)

## 5. 종료

![image](https://github.com/user-attachments/assets/0e5ab0b9-709e-4803-954f-e8c3d84b93f9)