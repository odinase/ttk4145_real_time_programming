static mut i : i32 = 0;

async fn thread_1() {
    unsafe {
        for _ in 0..1000000 {
            i += 1;
        }
    }
}


async fn thread_2() {
    unsafe {
        for _ in 0..1000000 {
            i -= 1;
        }
    }
}


fn main() {
    let f1 = thread_1();
    let f2 = thread_2();
    futures::join!(f1, f2);
    println!("i is {}!", i);
}
