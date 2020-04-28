
# list of nuclear weapon energy outputs in kilo-tons of TNT equivalence
# sourced: https://en.wikipedia.org/wiki/Nuclear_weapon_yield

import dash
import dash_core_components as dcc
import dash_html_components as html

#app = dash.Dash

app.layout = html.Div(children=[
    html.H1(children='Blast Simulation')

    dcc.Dropdown(
        options=[
            {'label': 'Davy Crockett', 'value': 0.02},
            {'label': 'AIR-2 Genie', 'value': 1.5},
            {'label': 'Little Boy', 'value': 18.0},
            {'label': 'Fat Man', 'value': 22.0},
            {'label': 'W76 warhead', 'value': 100.0},
            {'label': 'W87 warhead', 'value': 300.0},
            {'label': 'W88 warhead', 'value': 475.0},
            {'label': 'Ivy King', 'value': 500.0},
            {'label': 'Orange Herald Small', 'value': 720.0},
            {'label': 'B83 nuke', 'value': 1200.0},
            {'label': 'B53 nuke', 'value': 9000.0},
            {'label': 'Tsar Bomba', 'value': 50000.0},
            {'label': 'Sum_Tests', 'value': 510300.0}], 
        value='Choose an atomic bomb')

bombs = pd.DataFrame(atoms)
bombs
            {},
    
    
    
    
    
    
    ]
