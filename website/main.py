from flask import Flask, render_template, request, redirect, url_for, session
import os

app = Flask(__name__, static_url_path='/static')

app.secret_key = os.urandom(24)  # Vous pouvez également définir une clé secrète statique si vous préférez

mapstr = ""

def find_smalest_valid_id(fromid):
    for l in mapstr:
        if int(l.split(' ')[1]) == fromid:
            return find_smalest_valid_id(fromid + 1)
    return fromid

# Fonction pour ajouter un utilisateur au fichier texte
def add_user_to_file(pseudo, password, mail):
    with open("acount.txt", "r") as f:
        for line in f:
            if line.split(' ')[0] == pseudo:
                return False

    with open("acount.txt", "a") as f:
        f.write(f"{pseudo} {password} {mail}\n")
    return True

def verify_credentials(username, password):
    with open('acount.txt', 'r') as file:
        for line in file:
            l = line.split(' ')
            stored_username = l[0] 
            stored_password = l[1]
            if stored_username == username and stored_password == password:
                return True
    return False

@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']
    
    if verify_credentials(username, password):
        session['username'] = username
        return redirect(url_for('my_account'))
    else:
        return render_template('login.html', error="Identifiants invalides!")

@app.route('/my_account')
def my_account():
    if 'username' not in session:
        return redirect(url_for('register'))
    username = session['username']
    with open('acount.txt', 'r') as file: 
        for line in file:
            l = line.split(' ')
            if l[0] == username:
                nmonth = l[3]
    if int(nmonth) == 0:
        return "pour jouer il faut payer (1€ / mois)"
    with open('map.txt', 'r') as file: 
        for line in file:
            l = line.split(' ')
            if l[3] == username:
                return "<p> name : " + l[13] + "</p><p> hp : " + l[2] + "</p><p> leader : " + l[14] + '</p><a href="/logout">Disconnect</a>'
    return redirect(url_for('create_character'))


@app.route('/create_character.html', methods=['POST', 'GET'])
def create_character():
    global mapstr
    if 'username' not in session:
        return redirect(url_for('register'))
    if request.method == 'POST':
        with open('map.txt', 'r') as file:
            mapstr = file.read().splitlines()
            file.close()
            for line in mapstr:
                l = line.split(' ')
                if l[0] == 0 and l[13] == request.form['nom']:
                    return render_template('create_character.html', error="Un personnage avec le même nom existe déjà.")
        newid = find_smalest_valid_id(0)
        with open("map.txt", "a") as f:
            f.write(f"0 {newid} 10 {session['username']} 12.000000 75.00000 0.5 -1.000000 908.785156 e 0 99999 -1 {request.form['nom']} thyma none none 0 none none 0 none 0 3 0 0 empty empty empty empty empty test [] []\n")
        return redirect(url_for('my_account'))
    elif request.method == 'GET':
        return render_template('create_character.html')

# Route d'inscription
@app.route('/register.html', methods=['GET', 'POST'])
def register():
    if 'username' in session:
        return redirect(url_for('my_account'))
    else:
        if request.method == 'POST':
            # Récupérer les données du formulaire
            pseudo = request.form['pseudo']
            password = request.form['password']
            mail = request.form['mail']  

            # Ajouter l'utilisateur au fichier
            if add_user_to_file(pseudo, password, mail) == True:
            
            # Rediriger l'utilisateur vers une page de confirmation (ou autre page)
                return redirect(url_for('success'))
            else:
                return render_template('register.html', error="An account with the same name already exist")
    return render_template('register.html')

@app.route('/img/img1.png', methods=['GET', 'POST'])
def get_img_1():
    return render_template('img/img1.png')    

# Route de confirmation après l'inscription
@app.route('/success')
def success():
    return "Inscription réussie ! Vous êtes maintenant inscrit."

@app.route('/login.html')
def index():
    if 'username' in session:
        return redirect(url_for('my_account'))
    else:
        return render_template('login.html')

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/logout')
def logout():
    # Déconnecter l'utilisateur en supprimant la session
    session.pop('username', None)
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
