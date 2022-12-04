file = open("input.txt", "r")
count_fully = 0
count_overlap = 0

for pair in file:

    # Parsing
    line = pair.strip("\n").split(",")

    firstElf = line[0].split("-")
    firstElf[0] = int(firstElf[0])
    firstElf[1] = int(firstElf[1])

    secondElf = line[1].split("-")
    secondElf[0] = int(secondElf[0])
    secondElf[1] = int(secondElf[1])


    # Part 1
    if firstElf[0] <= secondElf[0] and secondElf[1] <= firstElf[1] or secondElf[0] <= firstElf[0] and firstElf[1] <= secondElf[1]:
        count_fully += 1


    # Part 2
    range1 = range(firstElf[0], firstElf[1] + 1)
    range2 = range(secondElf[0], secondElf[1] + 1)
    loop_finished = False

    for n1 in range1:
        for n2 in range2:
            if n1 == n2:
                count_overlap += 1
                loop_finished = True
                break
        if loop_finished:
            break


print("Count contain fully:", count_fully)
print("Count overlap:", count_overlap)

file.close()
