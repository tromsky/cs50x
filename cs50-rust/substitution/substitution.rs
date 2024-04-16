use std::collections::HashSet;
use std::env;
use std::io;
use std::process;

fn has_no_duplicates(key: &str) -> bool {
    let mut seen = HashSet::new();
    for character in key.chars() {
        // convert the character to lowercase
        let lowercase_c = character.to_lowercase().next().unwrap();
        // check if the character is already in the HashSet
        if seen.contains(&lowercase_c) {
            // Duplicate character found
            return false;
        }
        // if not, add it to the HashSet
        seen.insert(lowercase_c);
    }
    // no duplicates found
    return true;
}

fn get_text() -> String {
    let mut word = String::new();
    io::stdin()
        .read_line(&mut word)
        .expect("Failed to read line");

    let word = word.trim();
    return word.to_string();
}

fn main() {
    // get the command line args
    let args: Vec<String> = env::args().collect();

    // validate that one and only one arg was passed in
    if args.len() != 2 {
        eprintln!("Usage: {} <KEY>", args[0]);
        process::exit(1);
    }

    let key: &str = &args[1];
    // validate a 26-character key
    if key.len() != 26 {
        eprintln!("Key must be 26-characters");
        process::exit(1);
    }

    // check if the key contains invalid characters
    // should only contain A-z
    for character in key.chars() {
        if !character.is_alphabetic() {
            eprintln!("Key contains invalid characters");
            process::exit(1);
        }
    }

    // check if key contains duplicates
    if !has_no_duplicates(&key) {
        eprintln!("Key contains duplicate characters");
        process::exit(1);
    }

    // get plaintext
    println!("Enter plaintext and press enter.");
    let plaintext: &str = &get_text();

    // generate ciphertext
    let mut ciphertext = String::new();

    for character in plaintext.chars() {
        // if character is A-z
        if character.is_alphabetic() {
            // find the ordinal delta between the key and the alpahabet
            // 65 is ASCII 'A'
            let delta: usize = character.to_ascii_uppercase() as usize - 65;

            // append the substituion from the key
            // depending on upper or lowercase
            if character.is_uppercase() {
                let substitution: char = key.chars().nth(delta).unwrap().to_ascii_uppercase();
                ciphertext.push(substitution);
            } else {
                let substitution: char = key.chars().nth(delta).unwrap().to_ascii_lowercase();
                ciphertext.push(substitution);
            }
        // if character is not A-z, just append it
        } else {
            ciphertext.push(character);
        }
    }
    println!("ciphertext: {}", ciphertext);
}
