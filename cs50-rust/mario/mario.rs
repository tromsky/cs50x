use std::io;
use std::io::Write;

fn main() {
    let mut height: u32 = 0;

    while height < 1 || height > 8 {
        height = get_height();
    }

    print_tower(height);
}

fn get_height() -> u32 {
    loop {
        print!("Enter height: ");
        // needed for print!, to clear buffer
        io::stdout().flush().unwrap();

        let mut height = String::new();

        io::stdin()
            .read_line(&mut height)
            .expect("Failed to read line");

        let height: u32 = match height.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        return height;
    }
}

fn print_tower(height: u32) {
    // for each row
    let mut i = 1;
    while i <= height {
        // print spaces
        let mut j = 0;
        while j < height - i {
            print!(" ");
            j += 1;
        }

        // print left hashes
        let mut k = 1;
        while k <= i {
            print!("#");
            k += 1;
        }

        // print the gap
        print!("  ");

        // print the right hashes
        let mut l = 1;
        while l <= i {
            print!("#");
            l += 1;
        }

        // print new line and end the row
        println!("");
        i += 1;
    }
}
