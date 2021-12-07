import glob

TAGS = {
    r'(../../../../materials/': r'(../../materials/',
    r'(materials/': r'(../../materials/',
}  # oldname newname


def main():
    # reduce
    tags = dict(TAGS)
    for k, v in TAGS.items():
        if k == v:
            tags.pop(k)
    tot = 0
    worklist = glob.glob("*/*/*.md")
    for filename in worklist:
        text = []
        with open(filename, 'r', encoding='utf-8') as fin:
            text = fin.readlines()
        hit = 0
        for k, v in tags.items():
            if text[2].find(k) < 0:
                continue
            text[2] = text[2].replace(k, v)
            hit += 1
        if hit == 0:
            continue
        tot += 1
        with open(filename, 'w', encoding='utf-8') as fout:
            fout.writelines(text)
        print(f'{filename} done, replace {hit} point(s)')
    print(f'Update {tot} file(s). Job done.')


if __name__ == "__main__":
    main()
