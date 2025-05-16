def fixer(text):

    text = text.replace('.', '')            

    text = '_'.join(text.split())           

    filename = text + '.c'               


    with open(filename, 'w') as f:   

        f.write("")      


    print(f"{filename} created successfully!")


fixer("This is a test file.")