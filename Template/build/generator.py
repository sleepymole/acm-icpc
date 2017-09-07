import os

script_dir = os.path.split(os.path.realpath(__file__))[0]
root_dir = script_dir.replace('/build', '')

items = ['# Template\n']


def gen_md(path, depth):
    dirs = []
    for f in os.listdir(path):
        if os.path.isfile(path + '/' + f):
            items.append('* ' + f + '\n')
            with open(path + '/' + f) as fp:
                code = fp.read()
            items.append('``` cpp\n{}\n```'.format(code))
            items.append('\n' * 4)
        else:
            dirs.append(f)
    dirs.sort()
    for d in dirs:
        if path == root_dir and d == 'build':
            continue
        items.append('#' * (depth + 3))
        items.append(' ' + d + '\n')
        gen_md(path + '/' + d, depth + 1)


gen_md(root_dir, 1)
md = ''.join(items)
with open(script_dir + '/template.md', 'w') as f:
    f.write(md)
