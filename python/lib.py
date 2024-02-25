def filter(request):
    clean_rqst = request[:request.index('name=') + 5]
    for char in request[request.index('name=') + 5:]:
        if char.isalnum():
            clean_rqst += char
    return clean_rqst