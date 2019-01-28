use std::time::Instant;

const N: usize = 100000;

fn test() -> usize {
    let mut vec = vec![0;N];
    for i in 0..N {
        vec[i] = i;
    }
    let mut sum = 0;
    for i in 0..N {
        let a = vec[i];
        for b in &vec[i+1..N] {
            sum += a * b;
        }
    }
    sum
}

fn main() {
    let start = Instant::now();
    let result = test();
    let elapsed = start.elapsed();
    println!("{} duration was {}s {}ns", result, elapsed.as_secs(), elapsed.subsec_nanos());
}
