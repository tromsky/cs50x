use std::io;

fn main() {
    println!("-- Radability --");

    // Prompt the user for some text
    println!("Enter text and press return.");
    let text: &str = &get_text().to_lowercase();

    // count number of letters, words, and sentences
    let mut letter_count: usize = 0;
    let mut word_count: usize = 1;
    let mut sentence_count: usize = 0;

    for character in text.chars() {
        if character >= 'a' && character <= 'z' {
            letter_count += 1;
        } else if character == ' ' {
            word_count += 1;
        } else if character == '.' || character == '?' || character == '!' {
            sentence_count += 1;
        }
    }

    // Compute the Coleman-Liau index
    // index = 0.0588 * L - 0.296 * S - 15.8
    // L is the average number of letters per 100 words in the text
    //     the number of letters divided by the number of words, all multiplied by 100
    // S is the average number of sentences per 100 words in the text
    //     the number of sentences divided by the number of words, all multiplied by 100
    let average_letters: f32 = letter_count as f32 / word_count as f32 * 100.00;
    let average_sentences: f32 = sentence_count as f32 / word_count as f32 * 100.00;
    let index: f32 = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;
    let grade: usize = index.round() as usize;

    // output the grade level
    if grade < 1 {
        println!("Before Grade 1");
    } else if grade >= 16 {
        println!("Grade 16+");
    } else {
        println!("Grade {}", grade);
    }
}

fn get_text() -> String {
    let mut word = String::new();
    io::stdin()
        .read_line(&mut word)
        .expect("Failed to read line");

    let word = word.trim();
    return word.to_string();
}
