use std::time::Instant;

const N: usize = 100000;

fn testi() -> usize {
    let mut taulu = vec![0;N];
    for i in 0..N {
        taulu[i] = i;
    }
    let mut summa = 0;
    for i in 0..N {
        for j in i+1..N {
            summa += taulu[i] * taulu[j];
        }
    }
    summa
}

fn main() {
    let start = Instant::now();
    let tulos = testi();
    let elapsed = start.elapsed();
    println!("{} aikaa kului {}s {}ns", tulos, elapsed.as_secs(), elapsed.subsec_nanos());
}
