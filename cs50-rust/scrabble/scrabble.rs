use std::io;
use std::io::Write;

// const MY_STRING: &str = "Hello, world";
const POINTS: [usize; 26] = [
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10,
];
const ASCII_ALPHA_START: usize = 65;
const ASCII_ALPHA_END: usize = 90;

fn main() {
    // prompt the user for two words
    print!("Player 1: ");
    io::stdout().flush().unwrap();
    let word1: &str = &get_word();

    print!("Player 2: ");
    io::stdout().flush().unwrap();
    let word2: &str = &get_word();

    // computer the score for both words
    let player1_score: usize = compute_score(word1);
    let player2_score: usize = compute_score(word2);

    // determine the winner based on score
    if player1_score > player2_score {
        println!("Player 1 wins!");
    } else if player2_score > player1_score {
        println!("Player 2 wins!");
    } else {
        println!("Tie!");
    }
}

fn get_word() -> String {
    let mut word = String::new();
    io::stdin()
        .read_line(&mut word)
        .expect("Failed to read line");

    let word = word.trim();
    return word.to_string();
}

fn compute_score(word: &str) -> usize {
    let mut score: usize = 0;
    for letter in word.chars() {
        let position: usize = letter.to_ascii_uppercase() as usize;
        if position >= ASCII_ALPHA_START && position <= ASCII_ALPHA_END {
            score += POINTS[position - ASCII_ALPHA_START];
        }
    }
    return score;
}
