
# list of nuclear weapon energy outputs in kilo-tons of TNT equivalence
# sourced: https://en.wikipedia.org/wiki/Nuclear_weapon_yield

import dash
import dash_core_components as dcc
import dash_html_components as html
from dash.dependencies import Input, Output

import pandas as pd

# Step 1. Launch the application
app = dash.Dash(__name__)



# Step 2. Import the dataset
# Call function based on [dropdown choice(energyVal), smoothSlider(time)]

colors = {
    'background': '#111111',
    'text': '#7FDBFF',
}

# Dropdown -- name

# range slider -- time


# Step 3. Create a plotly figure
trace_1 = go.Scatter(x = , y = , 
                    name = 'Radius',
                    line = dict(width = 2, 
                                color = 'rgb(229, 151, 50)'))
layout = go.Layout(title = 'Time Series Plot',
                    hovermode = 'closest')
fig = go.Figure(data = [trace_1], layout = layout)

# Step 4. Create a Dash layout
app.layout = html.Div(style={'backgroundColor': colors['background']}, children=[
                # title of dashboard and a paragraph
                html.Div([
                    html.H1('Blast Simulation'),
                    html.P('Choose an atomic bomb from the dropdown\n
                            select a tab to decide between viewing a time series plot\n
                            of either the radius, velocity, or pressure of the shockwave.')],
                    style = {'padding': '50px',
                                'backgroundColor': '#3aaab2'}),
    
                # dropdown
                html.P([
                    html.Label("Choose an atomic weapon"),
                    dcc.Dropdown(id = 'opt', options = opts,
                                value = opts[0])
                        ], style = {'width': '400px',
                        

                
                # adding a plot
                dcc.Graph(id = 'plot', figure=fig),

                

                        

    


    # dropdown for user to select bomb
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
        value='Choose an atomic bomb'),
    
    # Name of bomb selected

    # dcc.Slider(time) updates dcc.Graph(rad, vel, press)
    dcc.Graph(id='graph-with-slider'),
    dcc.Slider(
        id='time-slider',
        min=,
        max=,
        value=,
        step=None),
])

@app.callback(
    Output('graph-with-slider', 'figure'),
    [Input('time-slider', 'value')])

def updateFig(selected_time):
    


if __name__ == '__main__':
    app.run_server(debug=True)
    print("executed")
