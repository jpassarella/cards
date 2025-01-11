import subprocess

from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def home():
    return render_template("determine_high_card.html")

@app.route("/execute/", methods = ["POST"])
def execute():
    card_rank_values = [request.form[f"rank_{i}"] for i in range(1, 6)]
    card_suit_values = [request.form[f"suit_{i}"] for i in range(1, 6)]
    
    card_value_string = ""
    for i in range(5):
        card_value_string += card_rank_values[i] + card_suit_values[i]
        
    # delete later, line of code below just used for error checking
    # return f"card_value_string = {card_value_string}"
    
    try:
        result = subprocess.run(['./determine_high_card.exe', card_value_string], capture_output = True, text = True)
        return f"Program output: {result.stdout}"
    except Exception as e:
        return f"Error running the program: {e}"

if __name__ == "__main__":
    app.run()