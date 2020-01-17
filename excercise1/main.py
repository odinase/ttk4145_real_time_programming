from threading import Thread

i = 0

def increment():
    global i
    for _ in range(1000000):
        i += 1


def decrement():
    global i
    for _ in range(1000000):
        i -= 1

def main():
    thread_1 = Thread(target=increment)
    thread_2 = Thread(target=decrement)
    thread_1.start()
    thread_2.start()
    thread_1.join()
    thread_2.join()
    print("i is now: {}".format(i))


if __name__ == "__main__":
    main()