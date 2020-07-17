# 간단한 테스트를 해보자

import plus_mod

print(plus_mod.plus_repeat(2,20000000))

c = 0
for i in range(0,20000000):
    c = c + 2
print(c)