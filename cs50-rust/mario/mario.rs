use std::fmt::Write;
use std::io;
use std::io::Write as OtherWrite;

fn main() {
    let mut height: usize = 0;

    while height < 1 || height > 8 {
        height = get_height();
    }

    print_tower(height);
}

fn get_height() -> usize {
    loop {
        print!("Enter height: ");
        // needed for print!, to clear buffer
        io::stdout().flush().unwrap();

        let mut height = String::new();

        io::stdin()
            .read_line(&mut height)
            .expect("Failed to read line");

        let height: usize = match height.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        return height;
    }
}

fn print_tower(total_height: usize) {
    let mut output = String::new();

    for height in 1..=total_height {
        writeln!(
            &mut output,
            "{padding} {blocks}  {blocks}",
            padding = " ".repeat(total_height - height),
            blocks = "#".repeat(height),
        )
        .unwrap();
    }

    print!("{output}");
}
