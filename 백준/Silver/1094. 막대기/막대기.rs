use std::io;

fn main() {
	let mut input = String::new();
	let mut x = 0;

	io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");

	x=input.trim().parse::<i32>().unwrap();

	//println!("{}",x);

	
	let mut count = 0;

	loop {
		if x%2==1 {count+=1;}
		if x==0 {break;}
		x=x/2;
	}
	println!("{count}");
}