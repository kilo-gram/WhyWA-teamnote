import sys
# 트릭: 함수 이름 덮어씌우기
# input = sys.stdin.read()

sys.stdin.read()
sys.stdin.readline()
sys.stdout.write() # 기본 줄바꿈 X 및 str만 가능

# 예제
print(sys.stdin.read()) # (입력 전체)
sys.stdout.write("Hello, World\n")