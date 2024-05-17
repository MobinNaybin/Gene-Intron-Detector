import os

# Write Compiled File Name Here
oFile = "intron-detector"

for i in range(8):
    os.system(
        f"./{oFile} < ./test-cases/intron-size-{i+1}.inp > ./actual-outputs/intron-size-{i+1}-out.txt"
    )

for i in range(50):
    os.system(
        f"./{oFile} < ./test-cases/increasing-size-{i+51}.inp > ./actual-outputs/increasing-size-{i+51}-out.txt"
    )

for i in range(30):
    os.system(
        f"./{oFile} < ./test-cases/many-solutions-{i+1}.inp > ./actual-outputs/many-solutions-{i+1}-out.txt"
    )

for i in range(6):
    os.system(
        f"./{oFile} < ./test-cases/non-exon-end-{i+1}.inp > ./actual-outputs/non-exon-end-{i+1}-out.txt"
    )

for i in range(6):
    os.system(
        f"./{oFile} < ./test-cases/non-exon-start-{i+1}.inp > ./actual-outputs/non-exon-start-{i+1}-out.txt"
    )


failnum = 0
for i in range(8):
    actualout = open(f"./actual-outputs/intron-size-{i + 1}-out.txt", "r")
    expectedout = open(f"./test-cases/intron-size-{i + 1}.out", "r")
    content = expectedout.readlines()
    expected = [line.split() for line in content]
    actual = list(actualout.read().split())

    if actual in expected:
        print("PASS")
    else:
        print("FAIL")
        failnum += 1


for i in range(50):
    actualout = open(f"./actual-outputs/increasing-size-{i+51}-out.txt", "r")
    expectedout = open(f"./test-cases/increasing-size-{i+51}.out", "r")
    content = expectedout.readlines()
    expected = [line.split() for line in content]
    actual = list(actualout.read().split())

    if actual in expected:
        print("PASS")
    else:
        print("FAIL")
        failnum += 1

for i in range(30):
    actualout = open(f"./actual-outputs/many-solutions-{i+1}-out.txt", "r")
    expectedout = open(f"./test-cases/many-solutions-{i+1}.out", "r")
    content = expectedout.readlines()
    expected = [line.split() for line in content]
    actual = list(actualout.read().split())

    if actual in expected:
        print("PASS")
    else:
        print("FAIL")
        failnum += 1


for i in range(6):
    actualout = open(f"./actual-outputs/non-exon-end-{i+1}-out.txt", "r")
    expectedout = open(f"./test-cases/non-exon-end-{i+1}.out", "r")
    content = expectedout.readlines()
    expected = [line.split() for line in content]
    actual = list(actualout.read().split())

    if actual in expected:
        print("PASS")
    else:
        print("FAIL")
        failnum += 1

for i in range(6):
    actualout = open(f"./actual-outputs/non-exon-start-{i+1}-out.txt", "r")
    expectedout = open(f"./test-cases/non-exon-start-{i+1}.out", "r")
    content = expectedout.readlines()
    expected = [line.split() for line in content]
    actual = list(actualout.read().split())

    if actual in expected:
        print("PASS")
    else:
        print("FAIL")
        failnum += 1


print(f"failed cases:{failnum}")
